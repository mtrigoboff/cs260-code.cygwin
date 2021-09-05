#include <cstring>

unsigned int hashFn1(char* str)
{
	unsigned int	hashCode{0};
	int				lgth{(int) strlen(str)};
	unsigned int	pow31;

	for (int i = 0; i < lgth; i++) {
		pow31 = 1;
		for (int j = 0; j < lgth - 1 - i; j++)
			// pow31 *= 31;
			asm(
			"		mov		%[pow31in], %%eax		\n"	
			"		imul	$31, %%eax				\n"
			"		mov		%%eax, %[pow31out]		\n"	
			:	[pow31in]	"=m"	(pow31)
			:	[pow31out]	"m"		(pow31)
			: "eax"
			);
		hashCode += str[i] * pow31;
		}

	return hashCode;
}

unsigned int hashFn2(char* str)
{
	unsigned int	hashCode{0};
	int				lgth{(int) strlen(str)};
	unsigned int	pow31{1};

	for (int i = lgth - 1; i >= 0; i--) {
		hashCode += str[i] * pow31;
		// pow31 *= 31;
		asm(
		"		mov		%[pow31in], %%eax		\n"	
		"		imul	$31, %%eax				\n"
		"		mov		%%eax, %[pow31out]		\n"	
		:	[pow31in]	"=m"	(pow31)
		:	[pow31out]	"m"		(pow31)
		: "eax"
		);
		}

	return hashCode;
}

unsigned int hashFn3(char* str)
{
	unsigned int	hashCode{0};
	int				lgth{(int) strlen(str)};
	unsigned int	pow31{1};

	for (int i = lgth - 1; i >= 0; i--) {
		hashCode += str[i] * pow31;
		pow31 = (pow31 << 5) - pow31;
		}

	return hashCode;
}
