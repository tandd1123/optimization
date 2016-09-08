//=============================================================================
/* 
*  File: DMMemoryPool.inl
*
*  Author: bing
*
*  Date: 2016-09-06
*
*  Version: v2.0
*
*  Github/Mail: https://github.com/binchen-china    <563853086@qq.com>
*
*  Note:
*/
//=============================================================================

template <typename T>
T** DMMemoryPool::require(T** src, DM_UINT size)
{
	_mutex_lock.acquire();
	DM_CHAR** p = nullptr;
    
	vector<DMMemoryPage*>::iterator it = _page.begin();
	for (; it != _page.end(); ++it)
	{
		if ((*it)->get_block_size() > size)
		{	
			p =(*it)->require();
			break;
		}
	}
        
	_mutex_lock.release();
    *src = reinterpret_cast<T*>(*p);
	return src;
}

template<typename T>
void DMMemoryPool::release(T** block, DM_UINT size)
{
	_mutex_lock.acquire();
    DM_CHAR** p = reinterpret_cast<DM_CHAR**>(block);
	vector<DMMemoryPage*>::iterator it = _page.begin();
	for (; it != _page.end(); ++it)
	{
		if ((*it)->get_block_size() > size)
		{
			(*it)->release(p);
			break;
		}
	}
	_mutex_lock.release();
}
