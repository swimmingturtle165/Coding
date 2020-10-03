#include <bits/stdc++.h>
using namespace std;

// Custom Comparator
bool mycomp(pair<long long  int ,long long int > a, pair<long long  int ,long long int > b){
    if(a.second != b.second)
        return a.second > b.second;
        
    return a.first < b.first;
}

int main()
{
	/*

		So here's what my solution approach is,

		Say a person has to give X money and take Y money. His net exchange amount would
		involve only one of the two actions, think about it!

		if X is bigger, then it means he has to give more money than take, so we can
		substitute everything by the statement "he has to give (X-Y) Money. it's the same

		So what we'll do, is we will calculate net exchange amount for all persons.

		Then we'll pick two person with maximum amount to give and maximum amount to take.

		Lets call the person with maximum amount to give as Person 1, and person with 
		maximum amount to take as Person 2.
		
		Now let's just say that Person 1 has to give amount_1, and Person 2 has to take 
		amount_2.

		There are 3 Possibility from here.

		1. If amount_1 is equal to amount_2

		   Well then we'll simply settle both of them and move to the next persons in line.

		2. If amount_1 is less than amount_2

		   Then we'll settle everthing for Person 1 as he has given what he had to give, but
		   the Person 2 hasn't taken all he had to take. So we'll move to the next giver in
		   the line

		3. If amount_2 is less than amount_1

		   Then we'll settle everthing for Person 2 as he has taken what he had to take, but
		   the Person 1 hasn't given all he had to give. So we'll move to the next taker in
		   the line.

		We'll store all the result all the transaction and output them in the end.

	*/



    // So let the hacking begin!  :P


    // We Input n and m.
	long long int n,m;cin>>n>>m;

	// I am making an array of size n to store all net_exchange amount or X-Y
    long long int amount[n+1];

    // I'll initialize it to 0
    fill(amount,amount+n+1,0);


    // If X-Y becomes negetive then the guy has to give only, else he'll take only
    for(int i=0 ; i < m ; i++){

        long long int u,v,d; cin >> u >> v >> d;
        
        amount[u] -= d; 
        amount[v] += d;
        
    }

    // We'll store all givers and takers like this , in a pair of integer.
	vector < pair< long long int , long long int > > giver, taker;
    
    
    // Here we are seperating givers from takers with their amounts.
    for(int i = 1; i <= n ; i++){

        if(amount[i] < 0){

        	// If amount is negetive, he's a giver
            giver.push_back({i,-amount[i]});
        
        }else if(amount[i] > 0){
        	
        	// If amount is positive, he's a taker
            taker.push_back({i,amount[i]});
        
        }   
    }
   

   	// Now i'm sorting the givers and takers by their maximum amount.
    sort(giver.begin(),giver.end(),mycomp);
    sort(taker.begin(),taker.end(),mycomp);


    // I'll use two pointers to simulate the process of transaction.
    // 'i' for givers, and 'j' for takers.
    int i = 0 , j = 0;


    // This vector will store the transaction.
    vector < pair< long long int, pair<long long int,long long int> > > res;


    // So this while loop will untill there is at least one person in any line givers/takers.

    while(i < giver.size()  &&  j < taker.size()){

        // Here are the Person 1, Person 2, amount_1 and amount_2 in consideration.
        long long int amount_1 = giver[i].second;
        long long int person_1 = giver[i].first;
        long long int amount_2 = taker[j].second;
        long long int person_2 = taker[j].first;


        if(amount_1 == amount_2){
        	// This is our first case, when amount_1 is equal to amount_2
        	res.push_back( { person_1 , { person_2 , amount_2 } } );

        	// We increment both pointers, to move to next persons in line.
        	i++;
        	j++;
        }else if(amount_1 < amount_2){

        	// This is our first case, when amount_1 is less than to amount_2
        	res.push_back( { person_1 , { person_2 , amount_1 } } );

        	// We increment 'i' pointers, to move to next giver in line.
        	i++;

        	// And taker has taken some money from the giver but he's still left to take more
        	// so we subtract the amount he took right now
        	taker[j].second-=amount_1;

        }else{

        	// This is our first case, when amount_1 is greater than to amount_2
        	res.push_back( { person_1 , { person_2 , amount_2 } } );

        	// We increment 'j' pointers, to move to next taker in line.
        	j++;

        	// And giver has given some money to the taker but he's still left to give more
        	// so we subtract the amount he gave right now
        	giver[i].second-=amount_2;	
        }
    }

    // We now output all transactions made.
    cout << res.size() << endl;

    for(auto x:res){
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    
    return 0;
}