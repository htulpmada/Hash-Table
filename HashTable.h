#include "Record.h"
#include <vector>
#include <iostream>

class HashTable
{
public:
	std::vector<Record>T;
	Record defa;	
	int count;


public:

	HashTable(){
	Record defa=Record();	
	for(int i=0;T.size()!=static_cast<std::vector<int>::size_type>(50000);i++)
	{
		T.push_back(defa);	
	}
}
int hashKey(std::string str){
	int HASH_SEED = 5381;
	int HASH_MULTIPLIER = 33;
	int HASH_MASK = unsigned(-1) >> 1;
	
	unsigned hash=HASH_SEED;
	int nchars=str.size();
	for(int i=0;i<nchars;i++){
		hash=HASH_MULTIPLIER*hash+str[i];
	}
	return(hash&HASH_MASK);
}
void addCount(int i){count=i;}
void upCount(){count++;}
void downCount(){count--;}
void collide(Record r,int i){
	if(i==49999){i=0;std::getchar();}
	if(T[i+1].screen_name!=""){
		//need to reset i to 0
		collide(r,i+1);}
	else{T[i+1]=r;}
}
void Put(Record r){
	int index;
	index=hashKey(r.screen_name)%50000;
	if(T[index].screen_name== ""){
		T[index]=r;
	}
	else if(T[index].screen_name== r.screen_name){
		T[index].Add(r.tweets[0],r.created_at[0]);
	} 
	else /*if(T[index].screen_name!= r.screen_name)*/{
		collide(r,index);
	}
	count++;
}

void Get(std::string s){}//Contains() returns index on table no need for function

void notFound(){std::cout<<"\nScreen Name not found press enter to try again:\n\n";}

int Contains(int index,std::string s){//combined with get() returns (-1) if not on table
	int i=index;
	//check table
	if(T[i].screen_name==s){return i;}
	while(T[i].screen_name!=s){
		if(T[i].screen_name==""){return -1;}
		//if (i < T.size){i=0}
		i++;
	}
	return i;
}

int Count(){
	std::cout<<"No. Of People:"<<count;
	return count;
}

void Remove(std::string s){
	int index=hashKey(s)%50000;
	int i=Contains(index,s);
	if(i!=(-1)){T[i]=defa;}
	else{notFound();}
}

void PrintTable(std::string name){
	int index=hashKey(name)%50000;
	int i=Contains(index,name);
	if(i!=(-1)){T[i].Print();}
	else{notFound();}

}
};