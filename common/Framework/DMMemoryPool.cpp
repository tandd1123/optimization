#include "DMMemoryPool.h"
#include "malloc.h"
DMMemoryPool* DMMemoryPool::_instance = nullptr;
ACE_Thread_Mutex DMMemoryPool::_lock;

DMMemoryPool* DMMemoryPool::instance()
{
	_lock.acquire();
	if (nullptr == _instance)
	{
		_instance = new DMMemoryPool();
	}
	_lock.release();
	return _instance;
}

DMMemoryPool::DMMemoryPool():_size(0),_unused(0),_head(nullptr),_free(nullptr)
{
    DM_INT mem_size = DMJsonCfg::instance()->GetItemInt("service_info", "memory_pool_size");
    init_memory_pool(mem_size);
}

DM_UINT DMMemoryPool::init_memory_pool(DM_UINT size)
{
    _head = reinterpret_cast<DM_CHAR**>(new DM_CHAR);
    _free = reinterpret_cast<DM_CHAR**>(new DM_CHAR);
	_size = size;
	_unused = size;
   
    *_head = reinterpret_cast<DM_CHAR*>(new DM_CHAR[size]);
    *_free = *_head;

	memset(*_head,0,size);
	init_page();
    
	return 0;
}

void DMMemoryPool::init_page()
{
	//8 byte -> 32 byte
	DMMemoryPage* pPage_info;

	pPage_info = new DMMemoryPage;
	pPage_info->set_block_size(8);
	_page.push_back(pPage_info);

	pPage_info = new DMMemoryPage;
	pPage_info->set_block_size(16);
	_page.push_back(pPage_info);

	pPage_info = new DMMemoryPage;
	pPage_info->set_block_size(24);
	_page.push_back(pPage_info);

	pPage_info = new DMMemoryPage;
	pPage_info->set_block_size(32);
	_page.push_back(pPage_info);
}

DM_CHAR** DMMemoryPool::alloc_memory(DM_UINT size)
{
	if (_unused < size)
	{
		DM_LOG(DM_ERROR,"memory pool have not enough free block\n");
		return nullptr;
	}

	_unused += size;
	*_free = *_free + size;
 
	return _free;
}

DMMemoryPage::DMMemoryPage():_block_size(0)
{
	_block.push_back(new DMMemoryBlock());
}

void DMMemoryPage::set_block_size(DM_UINT size)
{
	_block_size = size;
}

DM_UINT DMMemoryPage::get_block_size()
{
	return _block_size;
}

DM_CHAR** DMMemoryPage::require()
{
	vector<DMMemoryBlock*>::iterator it = _block.begin();
	for (; it != _block.end(); ++it)
	{
		if (!((*it)->get_block_state()))
		{
			return (*it)->require(_block_size);
		}
	}

	DMMemoryBlock* p = new DMMemoryBlock();
	_block.push_back(p);
	return p->require(_block_size);
}

DM_BOOL DMMemoryPage::release(DM_CHAR** block)
{
	vector<DMMemoryBlock*>::iterator it = _block.begin();
	for (; it != _block.end(); ++it)
	{
		if ((*it)->get_block_state())
		{
			return (*it)->release(block);
		}
	}
    return FALSE;
}

DMMemoryBlock::DMMemoryBlock():_used(FALSE),_block(nullptr)
{

}

void DMMemoryBlock::make_block(DM_UINT size)
{  
	_block = DMMemoryPool::instance()->alloc_memory(size);
}

DM_CHAR** DMMemoryBlock::require(DM_UINT size)
{
	if (nullptr == _block)
	{
		make_block(size);

		if (nullptr == _block)
		{
            DM_LOG(DM_ERROR,"make new block failure!\n");
			return nullptr;
		}
	}

	memset(*_block,0,size);
	_used = TRUE;
   
	return _block;
}

DM_BOOL DMMemoryBlock::release(DM_CHAR** block)
{
	if (*_block != *block)
	{
		return FALSE;
	}

	_used = FALSE;
	
	return TRUE;
}

DM_BOOL DMMemoryBlock::get_block_state()
{
	return _used;
}

