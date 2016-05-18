#pragma once

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>

#include "tree_node_t.hpp"

#define TREE_EPS 1E-3

using namespace std;

namespace AED {

    template <class T>
    class tree_t {
    private:
        tree_node_t<T>* root_;

    public:

	tree_t(void);
	~tree_t(void); 

	void insert(const T& data);

	tree_node_t<T>*& find(const T& data);
	tree_node_t<T>*  find(const T& data) const;

	int depth(void) const;
	int depth(tree_node_t<T>* root, int d) const;
	bool empty(void) const;

	ostream& write(ostream& os) const;

     private:

	int output_size(void) const;
	tree_node_t<T>*& find(tree_node_t<T>*& root, const T& data);
	tree_node_t<T>*  find(tree_node_t<T>*& root, const T& data) const;


	ostream& write(const T& dada, ostream& os) const;

	ostream& write(tree_node_t<T>* root, ostream& os) const;

	bool igual(const T& a, const T& b) const;
	bool menor(const T& a, const T& b) const;

	void clean(tree_node_t<T>*& root);
    };


	template <class T>
	tree_t<T>::tree_t(void) :
	root_(NULL){}

	template <class T>
	tree_t<T>::~tree_t(void) {

	clean(root_);
	}

	template <class T>
	void tree_t<T>::clean(tree_node_t<T>*& root)
	{
		if (root != NULL)
		{
			clean(root->get_left());
			clean(root->get_right());

			delete root;
			root = NULL;
		}
	}	

	template <class T>
	bool tree_t<T>::empty(void) const {

	if (root_ == NULL)
	   return true;
	else 
	   return false;
	}

	template <class T>
	tree_node_t<T>*& tree_t<T>::find(const T& data)
	{
		return find(root_, data);
	}

	template <class T>
	tree_node_t<T>* tree_t<T>::find(const T& data) const
	{
		return find(root_, data);
	}

	template <class T>
	void tree_t<T>::insert(const T& data) {

		tree_node_t<T>*& found = find(root_, data);

		if (found != NULL)
			cerr << "Elemento existente" << endl;
		else
			found = new tree_node_t<T>(data);
	}

    template <class T>
    bool tree_t<T>::igual(const T& a, const T& b)const {
        return a==b;
    }

	template <class T>
	bool tree_t<T>::menor(const T& a, const T& b) const
	{
		return a < b;
	}


	template <>
	bool tree_t<double>::igual(const double& a, const double& b) const
	{
        return fabs(a-b)< TREE_EPS;
	}

    template <>
    bool tree_t<double>::menor(const double& a, const double& b) const
    {
        return fabs(b-a) > TREE_EPS;
    }

	template <class T>
	tree_node_t<T>*& tree_t<T>::find(tree_node_t<T>*& root, const T& data)
	{
		if (root == NULL)
			return root;
		else{
			if (igual(root->get_data(), data))
				return root;
			else{
				if (menor(data, root->get_data()))
					return find(root->get_left(), data);
				else
					return find(root->get_right(), data);
			}
		}
	}

	template <class T>
	tree_node_t<T>* tree_t<T>::find(tree_node_t<T>*& root, const T& data) const
	{
		if (root == NULL)
			return root;
		else{
			if (igual(root->get_data(), data))
				return root;
			else{
				if (menor(data, root->get_data()))
					return find(root->get_left(), data);
				else
					return find(root->get_right(), data);
			}
		}
	}

	template <class T>
	int tree_t<T>::depth(tree_node_t<T>* root, int d) const 
	{
        if(root->get_left() != NULL){
            d++;
            depth(root->get_left(), d);

            if(root->get_right() != NULL){
                depth(root->get_right(),d);

                if(menor(d, depth(root->get_right(), d)))
                    return depth(root->get_right(), d);
            }
        }
                return d;
	}

	template <class T>
	int tree_t<T>::depth(void) const
	{
		return depth(root_, 0);
	}

	template <class T>
	int tree_t<T>::output_size(void) const 
	{
		return 4;
	}

	template <class T>
	ostream& tree_t<T>::write(const T& data, ostream& os) const
	{
		os << setw(output_size())<< data;
		return os;
	}


	template <class T>
	ostream& tree_t<T>::write(ostream& os) const {

		write(root_, os);
	
		return os;
	}	

	template <class T>
	ostream& tree_t<T>::write(tree_node_t<T>* root, ostream& os) const {
        if(root != NULL){
            write(root->get_left(), os);
            os << root->get_data() << " ";
            write(root->get_right(), os);
        }else
    		return os;
	}	

}
