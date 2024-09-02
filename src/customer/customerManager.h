#pragma once
#include <unordered_map>
#include "Observer.h"
#include "customer.h"
#include <vector> 
using namespace std;


class customerManager : public Observer{
private :
	
	static customerManager* instance;

	customerManager() : userCount(0) {};
	customerManager(const customerManager&) = delete;
	customerManager& operator=(const customerManager&) = delete;

	unordered_map<string, Customer> customermap;

	int userCount;

	const string filepath = "./data/customersList.csv";

public :
	static customerManager* getInstance();
	void getRegisteredUsers();
	int getuserCount() { return userCount;}

	Customer* getCustomer(string id) {
		return &customermap[id];
	}

	void update(const string& userId, const string& productName, int quantity) override {
		customermap[userId].updateTotalPurchase(quantity);
		updateUserInfo(customermap[userId]);
	}

	void showManageSystem();

	bool Login(const string& id, const string& pwd);
	bool registerUser(); // ȸ������
	void deleteUser(Customer& customer); // customermap ���� ���� ���� ����, txt���Ͽ� ������Ʈ 
	void addUser(Customer& customer);

	void showUserList(); // customermap ���� ��� (sorting ���� (totalpurchase ��, �̸���.. ?) ������)
	void showUserInfo(Customer& customer); // user �Ѹ� ���� ���� (id / pw / �̸� / ���� / ��ȭ��ȣ / �ּ� / �ѱ��űݾ� ) 
	void updateUserInfo(Customer& customer); // change ui + user ���� ���� �� txt ���Ͽ� ������Ʈ 
	void updateChangedUserInfo(Customer& customer); // user ���� ������ txt ���Ͽ� ������Ʈ 

	vector<Customer> getGroupList(Customer::Group group);

};

/* 

1. ������ �������� ���Ž� �� ���� / group ������Ʈ ���� üũ ->>>>> ����.

4. �׷�(Ƽ��) ���� -> �˸°� �����̳� ����Ʈ ���..?  ->>>> getter �ֱ� (Ƽ�� Ȯ���Ҽ��ְ� ��������߰�)
*/ 