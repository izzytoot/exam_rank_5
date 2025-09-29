#pragma once

#include "searchable_bag.hpp"

class set{
    private:
        searchable_bag& bag;
    public:
        set(searchable_bag& _bag);
        set(const set& src);
        set& operator= (const set& src);
        ~set();

    void insert(int value);
	void insert(int* array, int size) ;
	void print() const;
	void clear();

    searchable_bag& get_bag();
    bool has(int value);
};