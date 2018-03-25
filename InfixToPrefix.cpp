template <class T>
void infixToPrefix(string infix,StackType<T> stack){
	//pre: stack obj has been created and user input of infix string is present
	//post: infix string is converted to postfix
	string postfix;
	char top;
	for(int i=0; i< infix.length(); i++){
			 T n  = infix[i];
			 if(!isOperator(n)){//if operand go to string
				 postfix+=n;
			 }
			 else if(isOperator(n)){//if operator
				 if ((n!=')'&& stack.IsEmpty())||n=='(')
					 stack.Push(n);
				 else if(!stack.IsEmpty()&& n != ')'){//if something on stack and n isnt )
					 while(stack.Top() != '(' && opPrecedence(stack.Top(),n)){
						 top=stack.Top();
						 postfix+=top;
						 stack.Pop();
					 }
					 stack.Push(n);
				 }
				 else if(n == ')'){
					 while(!stack.IsEmpty() && stack.Top() != '('){
						 top=stack.Top();
						 postfix+=top;
						 stack.Pop();
					 }
					 stack.Pop();
				 }
			 }
	}
			 while (!stack.IsEmpty()){
				 if(stack.Top()!='('){
				 top=stack.Top();
				 postfix+=top;
				 stack.Pop();
				 }
				 else
					 stack.Pop();
				 cout<<"bottom while"<<endl;
			 }

	cout<<postfix<<endl;
}