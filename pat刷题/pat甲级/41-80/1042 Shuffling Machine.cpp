//#include<bits/stdc++.h>
//using namespace std;
//int shuff[55];
//struct Card{
//	char no;
//	int shuzi;
//	int pos;
//}card[55];
//int main(){
//	int k; cin>>k;
//	for(int i=1;i<=54;i++){
//		cin>>shuff[i];
//	}
//	int idx=1,idxx;
//	char x;
//	while(idx<=52){
//		if(idx<=13)
//		{
//			x='S';
//			idxx=idx;
//		}
//		else if(idx>13&&idx<=26){
//			x='H';
//			idxx=idx-13;
//		}
//		else if(idx>26&&idx<=39){
//			x='C';
//			idxx=idx-26;
//		}
//		else if(idx>39&&idx<=52){
//			x='D';
//			idxx=idx-39;
//		}
//		card[idx].no=x;
//		card[idx].shuzi=idxx;
//		card[idx].pos=idx;
//		idx++;
//	}
//	card[53].no='J';card[53].pos=53;card[53].shuzi=1;
//	card[54].no='J';card[54].pos=54;card[54].shuzi=2;
////	for(int i=1;i<=54;i++){
////		cout<<card[i].no<<card[i].shuzi<<" ";
////	}
//	while(k--){
//		for(int i=1;i<=54;i++){
//		Card temp=card[i];
//		card[i]=card[shuff[i]];
//		card[shuff[i]]=temp;
//		}
//	}
//	for(int i=1;i<=54;i++){
//		cout<<card[i].no<<card[i].shuzi<<" ";
//	}
//}
#include<bits/stdc++.h>
using namespace std;
char m[5]={'S','H','C','D','J'};
int Start[55],End[55],Next[55];
int main(){
	int k; cin>>k;
	for(int i=1;i<=54;i++)
		Start[i]=i;
		
	for(int i=1;i<=54;i++){
		cin>>Next[i];
	}
	
	for(int q=0;q<k;q++){
		for(int i=1;i<=54;i++){
			End[Next[i]]=Start[i];
			
		}
		for(int i=1;i<=54;i++){
			Start[i]=End[i];
		}
	}
	//1-13 1
	//14-26 2
	//27-39 3
	//40-52 4
	//53 54 5
	for(int i=1;i<=54;i++){
		Start[i]--;
		if(i!=54)
		cout<<m[(Start[i])/13]<<Start[i]%13+1<<" ";
		else
		cout<<m[(Start[i])/13]<<Start[i]%13+1;
	}
}
