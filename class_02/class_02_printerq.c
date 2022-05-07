#include <stdio.h>
#include <stdlib.h>

int main()
{
	int	test_num, doc_num, what_num, max, doc_idx, *doc, point = 0, count = 1;
	
	scanf("%d", &test_num);
	
	while (test_num-- > 0)
	{
		scanf("%d %d", &doc_num, &what_num);
		doc = (int *)malloc(doc_num * sizeof(int));

		doc_idx = -1;
		while (++doc_idx < doc_num)
			scanf("%d", &doc[doc_idx]);

		point = 0;
		count = 1;
		while (1)
		{
			max = 0;
			doc_idx = -1;
			while (++doc_idx < doc_num)
			{
				if (max < doc[doc_idx])
					max = doc[doc_idx];
			}
			
			while (doc[point] != max)
				point = (point + 1) % doc_num;

			if (point != what_num)	
			{
				doc[point] = 0;
				count++;
			}
			else
				break;
		}
		printf("%d\n", count);
		free(doc);
	}

	return (0);
}
