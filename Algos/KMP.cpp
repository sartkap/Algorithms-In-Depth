#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	string text,pattern;
	cin>>text>>pattern;


	int n = text.size();
	int m = pattern.size();
	
	// array count stores the largest length of prefix of string 'pattern' 
	// where the prefix equals the suffix of the current position of array
	int count[m];
	count[0] = 0;

	//initialize to zero
	for(int i = 0;i<m;i++){
		count[i]=0;
	}

	// i keeps track of current position of suffix
	// while j keeps track of current position of prefix
	int j = 0, i = 1; 
	while(i != m){
		
		if(pattern[i] == pattern[j]){
			count[i] = 1 + j;
			i++;
			j++;
		}
		else if(j == 0){
			count[i] = 0;
			i++;
		}
		else{
			if(count[i-1] == j && i==m-1){
				count[m-1] = 0;
				break;
			}
			j = count[i-1];

		}
		// to see how it works :- 
		//cout<<i<<" "<<m-1<<flush<<"\n";
	}
	for(int i = 0;i<m;i++){
		cout<<count[i]<<" "<<flush;
	}
	i = 0;
	j = 0;

	//flag to indicate if substring found or not
	int flag = 0;

	// to find substring 
	while(i!=n){

		// to see how algo works :- 
		//cout<<i<<" "<<j<<"\n"<<flush;


		if(pattern[j] == text[i]){
			if(j == m-1){ // substring found 
				flag = 1;
				break;
			}
			else{
				i++;
				j++;
			}
		}
		else if(i == 0){ 
			i++;
		}
		else{

			// to avoid ending up in an infinite loop and seg fault
			// if j is already equal to count[j-1] simply change i 
			if(j==0 || j == count[j-1]){ 
				i++;
				continue;
			}

			// else change j till either above condition is met 
			// or till it matches with pattern[i]
			j = count[j-1];
		}
	}

	if(flag == 1){
		cout<<"FOUND\n"<<i-m+1;
	}
	else {
		cout<<"NOT FOUND";
	}
	

	return 0;
}