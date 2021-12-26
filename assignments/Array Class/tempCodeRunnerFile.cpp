  //index lookup event loop 
  while(repeat == true){
    string input = ""; 
    int int_input;  
    cout << "Input an index for me to look up [Q to quit]:"; 
    getline(cin, input);  
    int_input = atoi(input.c_str()); 
    if(input == "Q" || input == "q"){
      repeat = false; 
    }else{
      if(array[int_input] != 0){
        printf("Found it-- the value stored at %i is %i\n", int_input, array[int_input]); 
      }else{
        cout << "I didn't find it\n"; 
      }
    }
  }