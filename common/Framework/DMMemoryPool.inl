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
	DM_CHAR** p = reinterpret_cast<DM_CHAR**>(new DM_CHAR);
    *p = nullptr;
	vector<DMMemoryPage*>::iterator it = _page.begin();
	for (; it != _page.end(); ++it)
	{
		if ((*it)->get_block_size() > size)
		{	
			p =(*it)->require();
			break;
		}
	}

    *src = reinterpret_cast<T*>(*p);
    
    if (nullptr == *src )
    {
        *src = new T;
    }
       
    _mutex_lock.release();
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
			if (!((*it)->release(p)))
            {
                exit(0);
            }
            *p = nullptr;
			break;
		}
	}
    
    if (nullptr != *p)
    {
        delete *block;
    }
    
	_mutex_lock.release();
}
