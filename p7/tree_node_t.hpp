#pragma once

#include <cstdio>

using namespace std;

namespace AED {

    template <class T>
    class tree_node_t {
    private:

        tree_node_t<T>* left_;
        tree_node_t<T>* right_;

	T data_;

    public:
	tree_node_t(const T& data);

	~tree_node_t(void);

	void set_left (tree_node_t<T>*);
	void set_right(tree_node_t<T>*);

	tree_node_t<T>*& get_left(void);
	tree_node_t<T>*& get_right(void);

	tree_node_t<T>* get_left(void)  const;
	tree_node_t<T>* get_right(void) const;

	void set_data(const T& data);
	T get_data(void) const;
};


	template <class T>
	tree_node_t<T>::tree_node_t(const T& data) :
	left_(NULL),
	right_(NULL),
	data_(data) 
	{}

	template <class T>
	tree_node_t<T>::~tree_node_t(void) {

	left_ = NULL;
	right_ = NULL;
	}

	template <class T>
	void tree_node_t<T>::set_left(tree_node_t<T>* left)
	{
		left_ = left;
	}

	template <class T>
	tree_node_t<T>* tree_node_t<T>::get_left(void) const
	{
		return left_;
	}

	template <class T>
	tree_node_t<T>*& tree_node_t<T>::get_left(void)
	{
		return left_;
	}

	template <class T>
	void tree_node_t<T>::set_right(tree_node_t<T>* right)
	{
		right_ = right;
	}

	template <class T>
	tree_node_t<T>* tree_node_t<T>::get_right(void) const
	{
		return right_;
	}

	template <class T>
	tree_node_t<T>*& tree_node_t<T>::get_right(void)
	{
		return right_;
	}

	template <class T>
	void tree_node_t<T>::set_data(const T& data)
	{
		data_ = data;
	}

	template <class T>
	T tree_node_t<T>::get_data(void) const
	{
		return data_;
	}


}
