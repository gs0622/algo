int priority(char op)
{
	switch (op) {
	case '*': case '/':  case '%': return 2;
	case '+': case '-': return 1;
	default: return 0;
}
}
void infix2postfix(char *in, char *out)
{
	int in_i = 0, out_j = 0, s_k = 1;
	char stack[32], c;
	while ('\0' != (c = in[in_i])) {
	switch (c) {
	case '+': case '-': case '*': case '/':  case '%':
		while (priority(c) > priority(stack[s_k]))
			out[out_j++] = stack[s_k--];
		stack[++s_k] = c, in_i+=1;
		break;
	case '(':
		stack[++s_k] = c, in_i+=1;
		break;
	case ')':
		while ('(' != stack[s_k])
			out[out_j++] = stack[s_k--];
		s_k-=1, in_i+=1;
		break;
	default: stack[++s_k] = in[in_i++];
}
}
}

