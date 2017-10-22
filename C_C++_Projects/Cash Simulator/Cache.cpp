#include<iostream>
#include <math.h> // for log
#include <bitset>
using namespace std;

char  chr;// reinput or no 
char  ReadWrite; // R/W opration
int   addres=0; // the target addres
char  cachebits; // the size in K or M
float block_size; // block size
int   word; // word size
int   num_of_Lines; // the number of lines in cache 
int   *array_cache; // veruial cache array
int   replacment_array[100];
float cache_size=0; 
float memory_size=0;
int   Mapping_type=0;
int   repalg=0;
int   WH=0; // Write Hit
int   WM=0; // Write Miss 
int   Length_of_addres;
int   num_of_blocks;
int   block;
int   Block;
int   line;
int   line_addres;
int   line_number;
int   tage;
bool  flag;
bool  *flag1;
int   flag2=0;
bool  flag3;
int   index=0;
float returnf; // refrence to comper
double base=2;
int   temp;
int   x=0;
void incorrect()
{
  cout<<"Try again with correct value as shown\n\n";
}
// to get the line addres 
int and_Opration(int line , int block)
{
  bitset<32>bin(block);
  if(line == 2)
    bin &=0x3 ;
  else if(line == 3)
    bin &=0x7;
  else if(line == 4)
    bin &=0xf;
  else if(line == 5)
    bin &=0x1f;
  else if(line == 6)
    bin &=0x3f;
  else if(line == 7)
    bin &=0x7f;
  else if(line == 8)
    bin &=0xff ;
  else if(line == 9)
    bin &=0x1ff;
  else if(line == 10)
    bin &=0x3ff;
  else if(line == 11)
    bin &=0x7ff;
  else if(line == 12)
    bin &=0xfff;
  else if(line == 13)
    bin &=0x1fff;
  else if(line == 14)
    bin &=0x3fff;
  else if(line == 15)
    bin &=0x7fff;
  else if(line == 16)
    bin &=0xffff;
  else if(line == 17)
    bin &=0x1ffff;
  else if(line == 18)
    bin &=0x3ffff;
  else if(line == 19)
    bin &=0x7ffff;
  else if(line == 20)
    bin &=0xfffff;
  else if(line == 21)
    bin &=0x1fffff;
  else if(line == 22)
    bin &=0x3fffff ;
  else if(line == 23)
    bin &=0x7fffff;
  else if(line == 24)
    bin &=0xffffff;
  else if(line == 25)
    bin &=0x1ffffff;
  else if(line == 26)
    bin &=0x3ffffff;
  else if(line == 27)
    bin &=0x7ffffff;
  else if(line == 28)
    bin &=0xfffffff;
  else if(line == 29)
    bin &=0x1fffffff;
  else if(line == 30)
    bin &=0x3fffffff;
  else if(line == 31)
    bin &=0x7fffffff;
  return bin.to_ullong();
}
void replacment()
{

}
// direct Mapping function
void direct_Mapp(int line , int block)
{
  line_addres = and_Opration(line , block);
  cout<<"\nline number :    "<<line_addres;
  tage = addres >> (line + word);
  cout<<"\nthe tage is :  "<<tage;
  // the block in the cache or not
  if(array_cache[line_addres] == block )
    flag = true;
  else
    flag = false;
  if(line_addres < num_of_Lines)
  {
    if(ReadWrite == 'W' || ReadWrite == 'w')
    {
      if(flag)	
      {
        if (WH == 1)
          cout<<"\nThe block is in the cache and Write-through is happend ";
        else
        {
          cout<<"\nThe block is in the cache ";	
          flag1 [line_addres]= true;  // diry bit 
        }
      }

      else 
      {
        if (WM == 1)
        {
          if(flag1[line_addres])
          {
            array_cache[line_addres] = block; // bring the block to the cache and write the value
            cout<<"\nWrite back for the old block";
            cout<<"\nAllocating the new block";	
          }
          else 
          {
            array_cache[line_addres] = block; // bring the block to the cache and write the value
            cout<<"\nAllocating the block";
          }
        }

        else
          cout<<"\nMiss and No-Write-allocate is happend ";
      }

    }
    else if (ReadWrite == 'R' || ReadWrite == 'r')
    {
      if(flag)
        cout<<"\nThe block is in the cache... ";

      else
      {
        array_cache[line_addres] = block;
        if(flag1[line_addres])
        {
          cout<<"\nWrite back for the old block";
          cout<<"\nAllocating block the new block";	
        }
        else 
        {
          cout<<"\nAllocating block the block";
        }
      }
    }
    else
      cout<<"\nthe input addres is not correct ..";

  }
}

void associative_Mapp()
{
  cout<<"\nindex : " <<index<<"\n\n";
  tage = block;
  cout<<"\nThe tage is :  "<<tage;
frist:
  if(index < num_of_Lines)
  {
    for(int i=0;i<=num_of_Lines;i++)
    {
      if(array_cache[i] == tage) 
      {
        flag = true; // the block in the cache
		cout<<"\nIndex I : " <<i;
        break;
      }
      else	
		 flag = false;
    }
	
    if(ReadWrite == 'W' || ReadWrite == 'w')
    {
      if(flag)	
      {
        if (WH == 1)
          cout<<"\nThe block is in the cache and Write-through is happend ";
        else
        {
		  index-=1;
          flag1[index] = true;
          cout<<"\nThe block is in the cache ";
		  index+=1;
        }
      }

      else 
      {
		cout<<"\nIndex : " <<index;
        if (WM == 1)
        {
          array_cache[index] = tage; // bring the block to the cache and write the value
          if(flag1[index])
          {
           cout<<"\nWrite back for the old block";
           cout<<"\nAllocating the new block";	
          }
          else
           cout<<"\nAllocating the block";
		  index+=1;
        }

        else
          cout<<"\nMiss and No-Write-allocate is happend ";
      }
    }
    else if (ReadWrite == 'R' || ReadWrite == 'r')
    {
      if(flag)
        cout<<"\nThe block is in the cache... ";
      else
      {
		cout<<"\nIndex : " <<index;
		array_cache[index] = tage;
		if(flag1[index])
		{
			cout<<"\nWrite back for the old block";
            cout<<"\nAllocating the new block";	
		}
		else
			cout<<"\nAllocating the block";	
		index+=1;
	  }
    }
  }
  else
  {
	  if(repalg == 2)
	{
		index = 0;
		goto frist;
		/*array_cache[index] = tage;
		cout<<"\nIndex : " <<index;
		if(flag1[index])
          {
            cout<<"\nWrite back for the old block";
            cout<<"\nAllocating the new block";	
          }
          else 
            cout<<"\nAllocating the block in the line 0 ";  
        index+=1;*/
	 }
  }
}
// to check for the value is in power of 2 
float intlog(double base, double x) // to get checked the value of the size 
{
  float clog= (float)(log(x) / log(base));
  float smalllog = clog - (int)clog ;
  return smalllog; // value less than 1 or equal 0 
}
// to determine if the numbers is in Kb or Mb 
int K_or_M( float size)
{
  int num;
  if(cachebits =='K' || cachebits =='k')
    num  =( size / block_size )*1000;
  else if(cachebits =='M' || cachebits =='m')
    num  =( size / block_size )*1000000;
  flag2 = 1;
  return num;
}
// input function 
int input(int word)
{
  //opration:
  cout<<"\n\n\nR/W Address : \n";
  cin>>ReadWrite;
  if(ReadWrite == 'e')
    exit(0);
  cin>>addres;
  //if(cachebits[0] !='R' && cachebits[0] !='r' && cachebits[0] !='W' && cachebits[0] !='w' ) 
  //{
  //cout<<"incorrect opration\n\n";
  //goto opration;
  //}
  //cout<<"Enter the target addres :\n";
  block = addres >> word;
  return block;
}
//error function

void main()
{
  //resive & check the size of the block ...
sizeofblock:
  cout<<"what is the block size  ?"<<'\n';
  cin>>block_size;
  returnf=intlog(base,block_size);
  if( block_size<0 || returnf<1 &&  returnf !=0  ) 
  {
    cout<<"incorrect value\n\n";
    goto sizeofblock;
  }
  word =log((double)block_size)/log(base);
  //resive & check the size of the cache ...
  cout<<"what is the Cache size  ?"<<'\n';
cache: 
  cin>>cache_size;
  returnf=intlog(base,cache_size);
  if( cache_size<0 || returnf <1 &&  returnf !=0  ) 
  {
    cout<<"incorrect value\n\n";
    goto cache;
  }

  cout<<"Mb or Kb ?\n";
valuecache:
  cin>>cachebits;
  if(cachebits =='b' || cachebits =='B')
  {
    num_of_Lines= cache_size / block_size;
    goto memory;
  }
  else if(cachebits !='M' && cachebits !='m' && cachebits !='K' && cachebits !='k' ) 
  {
    cout<<"incorrect size\n\n";
    goto valuecache;
  }
  // num_of_Lines on the cache 
  num_of_Lines= K_or_M(cache_size);

  //resive & check the size of the memory ...
memory:
  cout<<"what is the Memory size  ?"<<'\n';
  cin>>memory_size;
  returnf=intlog(base,memory_size);
  if( memory_size<0 || returnf<1 &&  returnf !=0  ) 
  {
    cout<<"incorrect value\n\n";
    goto memory;
  }

  cout<<"Mb or Kb ?\n";
valuememory:
  cin>>cachebits;
  if(cachebits =='b' || cachebits =='B')
  {
    num_of_blocks= memory_size / block_size;
    goto Mapping;
  }
  else if(cachebits !='M' && cachebits !='m' && cachebits !='K' && cachebits !='k' ) 
  {
    cout<<"incorrect size\n\n";
    goto valuememory;
  }
  num_of_blocks= K_or_M(memory_size);
  //Mapping
Mapping:
  cout<<"Enter the number of the type of mapping :\n";
  cout<<"1-Dirct Mapping... \n2-Associative Mapping...  \n3-Set-Associative Mapping... \n ";
  cin>>Mapping_type;
  if(Mapping_type<0 || Mapping_type>3 )
  {
    incorrect();
    goto Mapping;
  }
  if(Mapping_type == 3 || Mapping_type == 2)
    //Replacement algorithm
  {  
    cout<<"\nEnter the number of the replacement algorithm :\n";
    cout<<"1-LUR... \n2-FIFO...  \n3-LFU... \n4-Random... \n ";
replacment:
    cin>>repalg;
    if(repalg<0 || repalg>4 )
    {
      incorrect();
      goto replacment;
    }
  }

  // Write hit policy
  cout<<"What is the write-hit policy:\n";
  cout<<"1-Write-through... \n2-Write-back... \n ";
Hit:
  cin>>WH;
  if(WH<0 || WH>2 )
  {
    incorrect();
    goto Hit;
  }

  // Write miss policy
  cout<<"What is the write-miss policy:\n";
  cout<<"1-Write-allocate... \n2-No-Write-allocate... \n ";
Miss:
  cin>>WM;
  if(WM<0 || WM>2 )
  {
    incorrect();
    goto Miss;
  }

  //assume that the size of the block is 4-byte and the word is 4-byte. 
  Length_of_addres=log((double)memory_size)/log(base);
  if(cachebits =='K' || cachebits =='k')
  {
    Length_of_addres = Length_of_addres + 10;
  }
  else if(cachebits =='M' || cachebits =='m')
  {
    Length_of_addres = Length_of_addres + 20;
  }
  Block= Length_of_addres - word; // how many addres bit to describe the Block 
  // cache_size ... memory_size ... block_size ... word ... Length_of_addres ... num_of_Lines ... num_of_blocks
  array_cache = new int[num_of_Lines];
  flag1 =  new bool[num_of_Lines]();
  block = input(word);
  cout<<"////////////////////\\\\\\\\\\\\\\\\\\\\\\\\";
  cout<<"\nBasic data :";
  cout<<"\n1- Address fields : "<<Length_of_addres;
  cout<<"\n2- Word fields    : "<<word;
  cout<<"\n3- Block fields   : "<<Block;
  if(Mapping_type == 1)
  {
    if(flag2 == 1)
      line = ( log((double)num_of_Lines)/log(base) ) +1;
    else
      line = log((double)num_of_Lines)/log(base) ;
    tage = Block - line;
    cout<<"\n4- Lines fields : "<<line;
    cout<<"\n5- Tage fields  : "<<tage;
    cout<<"\n6- num of blocks: "<<num_of_blocks;
    cout<<"\n7- num of Lines : "<<num_of_Lines;
    cout<<"\n////////////////////\\\\\\\\\\\\\\\\\\\\\\\\";
    while(1)
    {
      direct_Mapp(line , block);
      input(word);
    }
  }

  else if(Mapping_type == 2)
  {
    tage = Block; 
    cout<<"\n4- Tage fields  : "<<tage;
    cout<<"\n5- num of blocks: "<<num_of_blocks;
    cout<<"\n6- num of Lines : "<<num_of_Lines;
    cout<<"\n////////////////////\\\\\\\\\\\\\\\\\\\\\\\\";
    while(1)
    {
      associative_Mapp(); // Block contant the number of bites
      input(word);
    }
  }
  cin>>x;
  delete []array_cache;
}

