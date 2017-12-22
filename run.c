#include <stdio.h>
#include <sys/types.h>
#include <limits.h>

#include "run.h"
#include "util.h"

void *base = 0;

 p_meta find_meta(p_meta *last, size_t size) {
  p_meta index = base;
  p_meta result = base;

  switch(fit_flag){
    case FIRST_FIT:
    {
     	//FIRST FIT CODE
	while(index){
           if(index->free==1&&index->size>=size){
	       result = index;
	       break;
	   }else
	       index=index->next;
	}
	if(!index)
	    result=index;
    }
    break;

    case BEST_FIT:
    {
      //BEST_FIT CODE
	p_meta temp=NULL;
	size_t min = 9999;
	while(index){
	    if(index->free==1&&index->size>=size){
		if(index->size<min){
		    temp=index;
		    min=index->size;
		}
	    }
	index=index->next;
	}
	result=temp;
    }
    break;

    case WORST_FIT:
    {
      //WORST_FIT CODE
	p_meta temp=NULL;
	size_t max=0;
	while(index){
	    if(index->free==1&&index->size>=size){
		if(index->size > max){
		    temp=index;
		    max=index->size;
		}
	    }index=index->next;
	}
	result = temp;
    }
    break;

  }
  return result;
}

void *m_malloc(size_t size) {

}

void m_free(void *ptr) {

}

void*
m_realloc(void* ptr, size_t size)
{

}
