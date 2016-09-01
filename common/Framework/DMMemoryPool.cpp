#include "DMMemoryPool.h"
#include "string.h"
#include <ace/Log_Msg.h>

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

int DMMemoryPool::init_memory_pool(int size)
{
	_size = size;
	_unused = size;
	_head = new char[size];
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

char* DMMemoryPool::alloc_memory(int size)
{
	if (_unused < size)
	{
		ACE_DEBUG((LM_INFO,"memory pool have not enough free block\n"));
		return nullptr;
	}

	_unused += size;
	char *p = _free;
	_free = _free + size;
	return p;
}

char* DMMemoryPool::require(int size)
{
	_mutex_lock.acquire();
	char* p = nullptr;
	std::vector<DMMemoryPage*>::iterator it = _page.begin();
	for (; it != _page.end(); ++it)
	{
		if ((*it)->get_block_size() > size)
		{	
			p =(*it)->require();
			break;
		}
	}
	_mutex_lock.release();
	return p;
}

/*
   size2?êy′óD?±?D?ó?éê??′óD?±￡3?ò???
*/
void DMMemoryPool::release(int size,char* block)
{
	_mutex_lock.acquire();
	std::vector<DMMemoryPage*>::iterator it = _page.begin();
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

void DMMemoryPage::set_block_size(int size)
{
	_block_size = size;
}

int DMMemoryPage::get_block_size()
{
	return _block_size;
}

char* DMMemoryPage::require()
{
	std::vector<DMMemoryBlock*>::iterator it = _block.begin();
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

void DMMemoryPage::release(char* block)
{
	std::vector<DMMemoryBlock*>::iterator it = _block.begin();
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

DMMemoryBlock::DMMemoryBlock():_used(false),_block(nullptr)
{

}

void DMMemoryBlock::make_block(int size)
{  
	_block = DMMemoryPool::instance()->alloc_memory(size);
}

char* DMMemoryBlock::require(int size)
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
	_used = true;

	return _block;
}

bool DMMemoryBlock::release(char* block)
{
	if (_block != block)
	{
		return false;
	}

	_used = false;
	
	return true;
}

bool DMMemoryBlock::get_block_state()
{
	return _used;
}

