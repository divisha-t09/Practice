#include<iostream>
using namespace std;

class Account
{
	protected:
	char accname[30];
	char acctype[10];
	int accnum;
	int bal;
	
	public:
		int amt;
		account()
		{
			bal=0;
		}
		
		void setdata()
		{
			cout<<"Enter name of the Account holder(without space): ";
			cin>>accname;
			
			cout<<"\nEnter Account Number: ";
			cin>>accnum;
			fflush(stdin);
			cout<<"\tEnter type of account: ";
			cin>>acctype;
		}
		void displaydata()
		{
			cout<<"\nName: "<<accname<<endl;
			cout<<"Account number: "<<accnum;
			cout<<"\t Account type: "<<acctype<<endl;
			cout<<"Balance: "<<bal;
		}
		
		void deposit()
		{
			int amt;
			cout<<"\nEnter the deposited amount: "<<endl;
			cin>>amt;
			bal=bal+amt;
		}
		
		void withdraw()
			{
			cout<<"\nEnter the amount you want to withdraw :"<<endl;
			cin>>amt;
			if(amt>bal)
			cout<<"\nInsuficient balance";
			else
			bal=bal-amt;
			}
};
	


class sav_acct: public Account
{
	int sinterest;
	
	public:
		int simple_int()
		{
			int r=4;
			int t;
			
			cout<<"Enter time: "<<t<<endl;
			sinterest=bal*(1+(r/100)*t);
			return(sinterest);
		}
		
		void update_bal(){
         bal=bal+sinterest;
        }

        void withdrawal(){
         int amt;
         cout<<"\n Enter amount to withdrawn";
         cin>>amt;
         if(bal>=amt){
               bal=bal-amt;
         }
         else{
               cout<<"\n The amount cannot be withdrawn";
         }
        }
};

class cur_acct:public Account
{
       int chq_bk;
       int penal;
       public:

       int min_bal(){
          int ret1=1;
          if(bal<=500){
             penal=50;
             bal=bal-penal;
             ret1=0;
          }
          else{
             cout<<"\n No penality imposed";
          }
          return ret1;
      }
      void withdrawal(){
          int amt;
          cout<<"\n Enter the amount to withdrawn";
          cin>>amt;
          int k=min_bal();
          if(k==1){
             if(bal>=amt)
             bal=bal-amt;
          }
          else{
              cout<<"\n The amount cannot be withdrawn";
          }
      }
   };

int main()
{
	sav_acct C1;
	cur_acct S1;
	C1.setdata();
	C1.displaydata();
	C1.deposit();
	C1.simple_int();
	C1.displaydata();
    C1.withdrawal();
    C1.displaydata();
    S1.setdata();
    S1.displaydata();
    S1.deposit();
    S1.displaydata();
    S1.withdrawal();
    S1.displaydata();
	
	return(0);
}
