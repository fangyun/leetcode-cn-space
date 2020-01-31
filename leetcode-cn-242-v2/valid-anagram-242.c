#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAnagram(char * s, char * t){
	int len = strlen(s);
	if (len != strlen(t)) {
		return false;
	}
	int counters[26] = { 0 };
	for(int i=0;i<len;i++){
		counters[s[i] - 'a']++;
		counters[t[i] - 'a']--;
	}
	for(int i=0;i<26;i++){
		if(counters[i]!=0){
			return false;
		}
	}
	return true;
}

int main(){
	printf("%d", isAnagram("anagram", "nagaram"));
	printf("%d",isAnagram("rat","car"));
	return 0;
}
