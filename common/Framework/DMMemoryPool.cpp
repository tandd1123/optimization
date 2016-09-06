#include "DMMemoryPool.h"

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

DM_UINT DMMemoryPool::init_memory_pool(DM_UINT size)
{
	_size = size;
	_unused = size;
	_head = new DM_CHAR[size];
	_free = _head;

	memset(_head,0,size);
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

DM_CHAR* DMMemoryPool::alloc_memory(DM_UINT size)
{
	if (_unused < size)
	{
		ACE_DEBUG((LM_INFO,"memory pool have not enough free block\n"));
		return nullptr;
	}

	_unused += size;
	DM_CHAR *p = _free;
	_free = _free + size;
      
	return p;
}

/*
   size2?êy′óD?±?D?ó?éê??′óD?±￡3?ò???
*/
void DMMemoryPool::release(DM_CHAR* block, DM_UINT size)
{
	_mutex_lock.acquire();
	vector<DMMemoryPage*>::iterator it = _page.begin();
	for (; it != _page.end(); ++it)
	{
		if ((*it)->get_block_size() > size)
		{
			(*it)->release(block);
			break;
		}
	}
	_mutex_lock.release();
}

DMMemoryPage::DMMemoryPage()
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

DM_CHAR* DMMemoryPage::require()
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

void DMMemoryPage::release(DM_CHAR* block)
{
	vector<DMMemoryBlock*>::iterator it = _block.begin();
	for (; it != _block.end(); ++it)
	{
		if ((*it)->get_block_state())
		{
			if ((*it)->release(block))
			{
				break;
			}
		}
	}
}

DMMemoryBlock::DMMemoryBlock():_used(FALSE),_block(nullptr)
{

}

void DMMemoryBlock::make_block(DM_UINT size)
{  
	_block = DMMemoryPool::instance()->alloc_memory(size);
}

DM_CHAR* DMMemoryBlock::require(DM_UINT size)
{
	if (nullptr == _block)
	{
		make_block(size);

		if (nullptr == _block)
		{
			return nullptr;
		}
	}

	memset(_block,0,size);
	_used = TRUE;

	return _block;
}

DM_BOOL DMMemoryBlock::release(DM_CHAR* block)
{
	if (_block != block)
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

