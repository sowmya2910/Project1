/**
 * @file conversion.c
 * @brief This file contains functions which perform basic data manipulation operations.
 *
 * @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
 * @date October 2, 2017
 *
 */

//***********************************************************************************
//Function Definitions
//***********************************************************************************
/******************************************************************//****
 * @brief my_itoa()
 * This function converts data from a standard integer type into an ASCII string
 * @data Data to be converted
 * @ptr Pointer which points to the resultant ASCII string
 * @base Integer value of the base to which conversion is to happen
 * @return Length of the converted data (including a negative sign)
 ***********************************************************************/
#include"conversion.h"
uint8_t my_itoa(int32_t data,uint8_t* ptr, uint32_t base)
{
 
uint8_t l=1;
int flag=0;
int8_t i=0,j=0;			       
uint8_t temp;

if(data==0)
  {
    *(ptr+l++)='0';
    return 0;
  }

if (data<0)
  {
   flag=1;
   data = -1*data;
  }

while(data!=0)
  {
   uint32_t remainder=data % base;
   if(remainder>9)
    {
      *(ptr+l++)=(remainder-10)+'a';
     }
   else
     {
      *(ptr+l++)= remainder+'0';
     }
 data = data/base;
  }

if(flag==1)
  {
   *(ptr+l++)='-';
  }


i=l-1;
j=0;
 while(j <i)				
       {
         temp= *(ptr+j);
         *(ptr+j) = *(ptr+i);
         *(ptr+i)=temp;
         j++;
         i--;
       }
*(ptr+l)='\0';
printf("%s\n",ptr);


//printf("%lu\n",l);
return l;
}

/******************************************************************//****
 * @brief my_atoi()
 * This function converts data from an ASCII string into an integer type
 * @ptr Pointer which points to the character string to convert
 * @digits Number of digits in the character set
 * @base Integer value of the base
 * @return Converted 32 bit signed integer
 ***********************************************************************/
int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base)
{
	int i=0,q=0;
int flag;
int32_t res=0;
int32_t value=0;
//int32_t multiplier=1;
int32_t counter=0;

if(*ptr == '-')
{

i++;
q++;
counter++;
flag=1;
}

if(base==10)
{
while(i<digits-1)
  {
res= res*10+*(ptr+i)-'0';
i++;
  }
}

if(base==2)
{
while(i<digits-1)
  {
   res = res + *(ptr+i) * (2^(digits-2-i));
   i++;
  }
}
if(base==16)
{


while(i<digits-1) 
  {
  if((*(ptr+i)-'0')>9)
   {
   value = *(ptr+i)-'a'+10;
   
   }
  else
  {
  value=*(ptr+i);
  value = value - '0';
  }  

i++;
res =res*16+value;
}
}
if(flag==1)
{
res= -1*res;
}
return res;
}



/******************************************************************//****
 * @brief big_to_little32()
 * This function converts an array of data in memory from big endian
 * representation to little endian
 * @data Memory location of data
 * @length Length of memory
 * @return If the conversion fails for any reason, an error is returned
 ***********************************************************************/
int8_t big_to_value32(uint32_t *data,uint32_t length)
{
    uint32_t value;
    if(length!=0)
    {
	/*The conversion is done from big to little endian */
    	value=((*data &0X000000FF)<<24)|((*data &0X0000FF00)<<8)|((*data &0X00FF0000)>>8)|((*data &0XFF000000)>>24);
	/* The value in little endian is printed */
        printf("The little endian term of %x is %x \n",*data,value);
	/* Length is decremented and data is incremented */
        length--;
        data++;
    }
    else
    {
    	return 0;
    }
return value;
}

/******************************************************************//****
 * @brief little_to_big32()
 * This function converts an array of data in memory from little endian
 * representation to big endian
 * @data Memory location of data
 * @length Length of memory
 * @return If the conversion fails for any reason, an error is returned
 ***********************************************************************/
int8_t little_to_big32(uint32_t *data,uint32_t length)
{
    	uint32_t value;
    	if(length!=0)
	{
		/* The conversion is done from little to big endian */
        	value=((*data &0X000000FF)<<24)|((*data &0X0000FF00)<<8)|((*data &0X00FF0000)>>8)|((*data &0XFF000000)>>24);
		/* The value in big endian is printed */
        	printf("The big endian term of %x is %x \n ",*data,value);
		/* Length is decremented and data is incremented */
        	length--;
        	data++;
    	}
    else
    {
    	return 0;
    }
return value;
}
