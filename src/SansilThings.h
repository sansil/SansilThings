/***
	Autor: sansil
	Inspirado en :https://github.com/thinger-io/Arduino-Library
***/


#ifndef SANSIL_THINGSV2_H
#define SANSIL_THINGSV2_H

#include "Recurso.h"

class sansilThing {

public:
	sansilThing() : head_(NULL), last_(NULL) {
	}

	virtual ~sansilThing() {
	}

public:
	struct entry {
		entry(const char* key) : key_(key), next_(NULL){}
		const char* key_;
		struct entry * next_; // es necesario este puntero ya que el tamaño de cada entry es variable
		recurso value_;
	};

private:
	entry * head_;
	entry * last_;
									
public:
	recurso* operator[](const char* key) {
		entry * current = head_;
		while (current != NULL) {
				if(strcmp(key, current->key_)==0){
						// current->value_.pchar = key;
						return &current->value_;
				}
				current = current->next_;
		}
		// TODO replace with memory allocator for allowing static memory/dynamic memory
		current = new entry(key);
		if(head_== NULL) head_ = current;
		if(last_ != NULL) last_->next_ = current;
		last_ = current;
		return &current->value_;
	}

  bool empty(){
		return head_ == last_;
  }

    void armar_msg(char* msg) {
      entry * current = head_;
      //resource_resource* rc;
      while (current != NULL) {
        //current->value_.execute();
        current = current->next_;
      }
    }

    // void run() {
    //   entry * current = head_;
    //   //resource_resource* rc;
    //   while (current != NULL) {
    //     current->value_.execute();
    //     current = current->next_;
    //   }
      
    // }

};

#endif