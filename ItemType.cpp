#include "ItemType.h"
#include <iostream>
#include <cstddef>

using namespace std;

ItemType::ItemType(){

}

//Compares given items
RelationType ItemType::compareTo(ItemType &item){
	if(item.getValue() < this->getValue()){
		return GREATER;
	}
	else if(item.getValue() > this->getValue()){
		return LESS;
	}
	else{
		return EQUAL;
	}
}

//Print item value
void ItemType::print(){
	cout << this->value << endl;
}

//Initialize item
void ItemType::initialize(int number){
	this->value=number;
}

//Return item value
int ItemType::getValue() const{
	return this->value;	
}
