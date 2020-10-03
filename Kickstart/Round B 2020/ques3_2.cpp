

void evaluate(string tokens){ 
    int i; 
      
    stack <int> values,curr_x,curr_y; 
    curr_x.push(0);
    curr_y.push(0);

      
    stack <char> ops; 
      
    for(i = 0; i < tokens.length(); i++)
    { 
          
        // Current token is a whitespace, 
        // skip it. 
        if(tokens[i] == ' ') 
            continue; 
          
        // Current token is an opening  
        // brace, push it to 'ops' 
        else if(tokens[i] == '(')
        { 
            ops.push(tokens[i]); 
            curr_x.push(0);
            curr_y.push(0);
        } 
          
        // Current token is a number, push  
        // it to stack for numbers. 
        else if(tokens[i]>='2' && tokens[i]<='9')
        { 
            int val = tokens[i]-'0';            
           
              
            values.push(val); 
        } 
          
        // Closing brace encountered, solve  
        // entire brace. 
        else if(tokens[i] == ')') 
        { 
            ll  v1=curr_x.top();
            ll  v2=curr_y.top();
            ll val=values.top();
            
            curr_x.pop();
            curr_y.pop();
            values.pop();

            v1*=val;
            v2*=val;
            curr_x.push(v1);
            curr_y.push(v2);              
            
        } 
          
        else
        { 
            if(tokens[i]=='N')
            {

                ll v=curr_x.top();
                curr_x.pop();
                v++;
                curr_x.push(v);
            }
            if(tokens[i]=='S')
            {

                ll v=curr_x.top();
                curr_x.pop();
                v--;
                curr_x.push(v);
            }
            if(tokens[i]=='E')
            {

                ll v=curr_y.top();
                curr_y.pop();
                v++;
                curr_y.push(v);
            }
            if(tokens[i]=='W')
            {

                ll v=curr_y.top();
                curr_y.pop();
                v--;
                curr_y.push(v);
            }
             
              
           
        } 
    } 
      
    // Entire expression has been parsed at this 
    // point, apply remaining ops to remaining 
    // values. 
    ll x=0,y=0;
    while(!curr_x.empty()){ 
        x+= curr_x.top(); 
        curr_x.pop(); 
                  
         y+= curr_x.top(); 
        curr_x.pop(); 
                  
       
                  
         
    } 
    ll sfsdf=ntothepowerm(10,9);
    x+=sfsdf;
    y+=sfsdf;
    if(x>sfsdf)
    {
        x-=sfsdf;
    }
    if(y>sfsdf)
    {
        y-=sfsdf;
    }
      cout<<x<<" "<<y<<endl;
    // Top of 'values' contains result, return it. 
     
} 