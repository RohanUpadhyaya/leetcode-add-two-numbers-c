#include <stdlib.h>
#include<stdio.h>
#include<string.h>


int lengthOfSubstring(char *s)
{
	int n =	strlen(s);

	int maxLen = 0;

	for(int i=0;i<n;i++)
	{
		int len = 0;
		int seen[128] = {0};

		for(int j = i; j< n;j++)
		{
			if(seen[(int)s[j]])
			{
				break;

			}

			seen[(int)s[j]] = 1;
			len++;

		}

		if(len>maxLen)
		{
			maxLen = len;

		}

	}

	return maxLen;

}

int main()
{
	int result = lengthOfSubstring("abcdefafakjdhakhakdhakdhakadhkadkahdkhad");

	printf("%d\n" , result);

	return 0;
}

			
