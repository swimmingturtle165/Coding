int n=input1+input2;
	int* arr =new int[n+1];
	for(int i = 0;i<n+1;i++)
	{
		arr[i]=0;
	}
	for(int i = 1;i<n+1;i++)
	{
		for(int j=1;j*i<n+1;j++)
		{
			arr[i*j]++;
		}
	}
	int ans=0;
	int m=input2;
	deque<int> Qi(m); 
  
    
    int i; 
    for (i = 1; i <=m; i++) { 
       
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) 
            Qi.pop_back(); // Remove from rear 
  
        
        Qi.push_back(i); 
    } 
  
   
    for (; i <= input1+1; i++) { 
        
       ans+=arr[Qi.front()]; 
  
        
        while ((!Qi.empty()) && Qi.front() <= i - m) 
            Qi.pop_front(); 
  
       
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) 
            Qi.pop_back(); 
  
       
        Qi.push_back(i); 
    } 
  
   
	return ans;