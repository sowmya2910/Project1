/**
* @file memory.h
* @brief An abstraction for functions containing memory manipulation operations
*
* This header file provides an abstraction of manipulating memory via function calls.
*
* @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
* @date October 2, 2017
*
*/
#ifndef __MEMORY_H__
#define __MEMORY_H__
//***********************************************************************************
// Include files
//***********************************************************************************
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>

//***********************************************************************************
// function prototypes
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
uint8_t* my_memmove(uint8_t* src, uint8_t* dst, size_t length);

/******************************************************************//****
 * @brief my_memcpy()
 * This function copies bytes of data from source to destination and
 * does not handle overlap of source and destination
 * @src Memory location of source data
 * @dst Memory location of destination data
 * @length Number of bytes to be moved
 * @return Pointer to the destination
 ***********************************************************************/
uint8_t* my_memcpy(uint8_t* src, uint8_t* dst, size_t length);

/******************************************************************//****
 * @brief my_memset()
 * This function sets all locations of a memory to a given value
 * @src Memory location of source data
 * @length Number of bytes to be set
 * @value Value to be set
 * @return Pointer to the source
 ***********************************************************************/
uint8_t* my_memset(uint8_t* src, size_t length, uint8_t value);

/******************************************************************//****
 * @brief my_memzero()
 * This function zeros out all the memory
 * @src Memory location of source data
 * @length Number of bytes to be zero-d
 * @return Pointer to the source
 ***********************************************************************/
uint8_t* my_memzero(uint8_t* src, size_t length);

/******************************************************************//****
 * @brief my_reverse()
 * This function reverses the order of all the bytes
 * @src Memory location of source data
 * @length Number of bytes to be reversed
 * @return Pointer to the source
 ***********************************************************************/
uint8_t* my_reverse(uint8_t* src, size_t length);

/******************************************************************//****
 * @brief reserve_words()
 * This function allocates words in dynamic memory
 * @length Number of words to be allocated
 * @return If operation is successful, pointer to the allocation is returned
 * If operation is not successful, NULL pointer is returned
 ***********************************************************************/
int32_t* reserve_words(size_t length);

/******************************************************************//****
 * @brief free_words()
 * This function frees an allocated dynamic memory
 * @src Pointer pointing to memory allocation
 * @return void
 ***********************************************************************/
void free_words(int32_t* src);


#endif /* __MEMORY_H__ */
