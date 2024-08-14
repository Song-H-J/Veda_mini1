#pragma once
#include <unordered_map>
using namespace std;

class Customer;

class customerManager {
private :
	
	static customerManager* instance;

	customerManager() {	}
	customerManager(const customerManager&) = delete;
	customerManager& operator=(const customerManager&) = delete;

	unordered_map<string, Customer> customermap;
	int userCount;

public :
	static customerManager* getInstance() {
		if (instance == nullptr) {
			instance = new customerManager();
		}
		return instance;
	}

	void showManageSystem();

	void addUser(); // txt ���Ͽ��� ���� ���� �޾ƿͼ� customermap�� ����
	void deleteUser(Customer& customer); // customermap ���� ���� ���� ����, txt���Ͽ� ������Ʈ 
	void showUserList(); // customermap ���� ��� (sorting ���� (totalpurchase ��, �̸���.. ?) ������)
	void showUserInfo(Customer& customer); // user �Ѹ� ���� ���� (id / pw / �̸� / ���� / ��ȭ��ȣ / �ּ� / �ѱ��űݾ� ) 
	void updateUserInfo(Customer& customer); // user ���� ���� �� txt ���Ͽ� ������Ʈ

	void addUserToGroup(const string& userId, const string& groupName); 
	void removeUserFromGroup(const string& userId, const string& groupName);

};

/* 

1. ������ �������� ���Ž� �� ���� / group ������Ʈ ���� üũ ->>>>> ����.
2. ���ǳ��� ��ȸ���? Ȥ�� ä��..? ->>>> ���߿�..
3. �� �ı� ���� ->>>>> ���߿� ..
4. �׷�(Ƽ��) ���� -> �˸°� �����̳� ����Ʈ ���..?  ->>>> getter �ֱ� (Ƽ�� Ȯ���Ҽ��ְ� ��������߰�)
5. ����id ���� �־�� �Ϸ���..?  -- >>> ����

int uniqueId; // manager gives it
	string userId;
	string userPassword;
	string userName;
	bool userGender; // 0 female, 1 male

	string userPhoneNumber;
	string userAddress;

	int totalPurchase;


*/ 