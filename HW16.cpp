#include <iostream>
#include <vector>
using namespace std;

int main(){
	int i, j, k;
	int test_cases;
	cin >> test_cases;
	for(k=0; k<test_cases; k++){
		///input///
		vector<long long int> v;
		long long int next;
 
		while(cin.get() != '\n'){
			cin >> next;
			v.push_back(next);
		}
			
		///logic///
		vector<long long int> ans;
		int count=0, max_count=0;
		//�]�w�ˬd�I
		for(i=0; i<v.size(); i++){
			//�H�ˬd�I�����ߩ�����񥦧�j����
			for(j=i-1; j>=0; j--){
				if(v[i] < v[j]){
					count++;
				}
			}
			//�H�ˬd�I�����ߩ��k��񥦧�p����
			for(j=i+1; j<v.size(); j++){
				if(v[i] > v[j]){
					count++;
				}
			}
			//�p�G�ϧǼƭӼƬۦP 
			if(count == max_count)	ans.push_back(v[i]);//�N�ˬd�I���ans�̭� 
			//�P�_�ϧǼƬO���O�̤j��
			if(count > max_count){
				ans.clear();
				max_count = count;
				ans.push_back(v[i]);
			}
			count = 0;
		}
		///output///
		cout << ans[0];
		for(i=1; i<ans.size(); i++){
			cout << ", " << ans[i];  
		}
		cout << " " << max_count << endl;
	}
	return 0;
} 
