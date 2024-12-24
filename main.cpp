#include<iostream>
#include<vector>
#include "data.h"
using namespace std;

vector<Product> allProducts = {
    Product(1,"iphone 16",70000),
    Product(2,"portronics keyboard&mouse",4000),
    Product(3,"jbl tune beam buds",5000),
    Product(5,"lenovo ideapad",60000),
    Product(4,"seagate hard-disk",2000),
    Product(6,"firebolt watch",3000),
    Product(7,"apple",12),
    Product(8,"dragonfruit",100),
    Product(9,"potato(1kg)",39),
    Product(10,"tomato(1Kg)",45),
    Product(11,"onion(1Kg)",49),
    Product(12,"battery",99)
};

Product* chooseProduct(){

	//Display the list of products
	string productList;
	cout<<"Available Products "<<endl;

	for(auto product : allProducts){
		productList.append(product.getDisplayName());
	}
	cout << productList <<endl;

	cout<<"----------------"<<endl;
	string choice;
	cin>>choice;
	for(int i=0; i < allProducts.size(); i++){
		if(allProducts[i].getShortName()==choice){
			return &allProducts[i];
		}
	}
	cout<<"Product not found!" <<endl;
	return NULL;
}

bool checkout(Cart &cart){
	if(cart.isEmpty()){
		return false;
	}

	int total = cart.getTotal();
	cout<<"Pay in Cash";

	int paid;
	cin>> paid;

	if(paid>=total){
		cout<<"Change " <<paid - total << endl;
		cout<<"Thank you for shopping!";
		return true;
	}

	else{
		cout<<"Not enough cash!";
		return false;
	}

}

int main(){

	char action;
	Cart cart;

	while(true){
		cout<<"Select an action -  (a)dd item, (v)iew cart, (c)heckout" <<endl;
		cin>> action;

		if(action=='a'){
			//Todo: Add to Cart 
			// View All Products + Choose Product + Add to the Cart 
			Product * product = chooseProduct();
			if(product!=NULL){
				cout<<"Added to the Cart "<<product->getDisplayName() <<endl;
				cart.addProduct(*product);
			}

		}
		else if(action=='v'){
			// View the Cart
			cout<<"------------------" <<endl;
			cout << cart.viewCart();
			cout<<"------------------"<<endl;
		}
		else{
			// Checkout 
			cart.viewCart();
			if(checkout(cart)){
				break;
			}
		}
	}

	return 0;
}
