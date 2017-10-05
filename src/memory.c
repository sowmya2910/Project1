/**
 * @file memory.c
 * @brief This file contains functions which perform memory manipulation operations.
 *
 * @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
 * @date October 2, 2017
 *
 */

//***********************************************************************************
//Function Definitions
//***********************************************************************************
/******************************************************************//****
 * @brief my_memmove()
 * This function copies bytes of data from source to destination and
 * handles overlap of source and destination
 * @src Memory location of source data
 * @dst Memory location of destination data
 * @length Number of bytes to be moved
 * @return Pointer to the destination
 ***********************************************************************/
#include"memory.h"
uint8_t* my_memmove(uint8_t *src,uint8_t *dst,size_t length)
{
    uint32_t i=0;
    /* Check for NULL condition and finite length */
    if((src !=NULL) && (dst !=NULL) && (length >=0))
    {
    /* Check for address overlap */
        if(src<dst)
        {
            if((src+length)>dst)
    		{
                /* Run for loop */
      			for(i=length;i>0;i--)
     			{
                        /* Copy operation */
          			*(dst+(i-1))= *(src+(i-1));
      			}
    		}
    		else /* If there is no address overlap */
    		{
    		/* Run for loop */
      			for(i=0;i<length;i++)
     			{
                        /* Copy operation */
          			*(dst+i)= *(src+i);
      			}
    		}
         }
            else
            {
      	    /* Run for loop */
      		for(i=0;i<length;i++)
     		{
                /* Copy operation */
         	 	*(dst+i)= *(src+i);
      		}
            }
    		
     }
     else
     {
	/* NULL */
     }
     /* Return pointer to destination */
     return dst;

}


/******************************************************************//****
 * @brief my_memcpy()
 * This function copies bytes of data from source to destination and
 * does not handle overlap of source and destination
 * @src Memory location of source data
 * @dst Memory location of destination data
 * @length Number of bytes to be moved
 * @return Pointer to the destination
 ***********************************************************************/
uint8_t* my_memcpy(uint8_t *src,uint8_t *dst,size_t length)
{
    uint32_t i=0;
    /* Check for NULL condition and finite length */
    if((src !=NULL) && (dst !=NULL) && (length >=0))
    {
        /* Run for loop */
        for( i=0;i<length;i++)
        {
            /* Data copy operation */
            *(dst+i)= *(src+i);
        }
    }
    else /* NULL condition or length is less than or equal to zero */
    {
        /* NULL */
    }
    /* Return pointer to the destination */
    return dst;
}


/******************************************************************//****
 * @brief my_memset()
 * This function sets all locations of a memory to a given value
 * @src Memory location of source data
 * @length Number of bytes to be set
 * @value Value to be set
 * @return Pointer to the source
 ***********************************************************************/
uint8_t* my_memset(uint8_t* src, size_t length, uint8_t value)
{
    uint32_t i=0;
    /* Check for NULL condition and finite length */
    if((src !=NULL) && (length >=0))
    {
        /* Run for loop */
       for(i=0;i<length;i++)
        {
            /* Replace memory with the value */
            *(src+i) = value;
        }
    }
    else /* NULL condition or length is less than or equal to zero */
    {
        /* NULL */
    }
    /* Return pointer to the source */
    return src;
}


/******************************************************************//****
 * @brief my_memzero()
 * This function zeros out all the memory
 * @src Memory location of source data
 * @length Number of bytes to be zero-d
 * @return Pointer to the source
 ***********************************************************************/
uint8_t* my_memzero(uint8_t *src, size_t length)
{
    uint32_t i=0;
    /* Check for NULL condition and finite length */
    if((src != NULL) && (length > 0))
    {
	for(i=0;i<length;i++)
	{
        /* Zero out the memory by replacing 0 in source data */
        	*(src+i)=0;
        }
    }
    else
    {
	/*NULL*/
    }
    /* Return pointer to the source */
    return src;
}


/******************************************************************//****
 * @brief my_reverse()
 * This function reverses the order of all the bytes
 * @src Memory location of source data
 * @length Number of bytes to be reversed
 * @return Pointer to the source
 ***********************************************************************/
uint8_t* my_reverse(uint8_t *src,size_t length)
{
    uint8_t temp=0;
    uint32_t i,j;
    i=0;
    j=length-1;
    /* Check if i is less than j */
    while(i<j)
    {
    /* Swapping operation */
        temp=*(src+i);
        *(src+i)=*(src+j);
        *(src+j)=temp;
        /* Increment i and decrement j */
        i++;
        j--;
    }
    /* Return pointer to the source */
    return src;
}


/******************************************************************//****
 * @brief reserve_words()
 * This function allocates words in dynamic memory
 * @length Number of words to be allocated
 * @return If operation is successful, pointer to the allocation is returned
 * If operation is not successful, NULL pointer is returned
 ***********************************************************************/
int32_t* reserve_words(size_t length)
{
    int32_t *a;
    /* Check if length is finite */
    if(length>0)
    {
        /* Allocate dynamic memory */
        a=(int32_t*) malloc (length*sizeof(int32_t));
    }
    else /* If length is not finite */
    {
        /* NULL pointer is used */
        a=NULL;
    }
    /* Returns pointer to the allocation */
    return a;
}


/******************************************************************//****
 * @brief free_words()
 * This function frees an allocated dynamic memory
 * @src Pointer pointing to memory allocation
 * @return void
 ***********************************************************************/
void free_words(int32_t* src)
{
        /* Free the allocated dynamic memory */
        free(src);
}
