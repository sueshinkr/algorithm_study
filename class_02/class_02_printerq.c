#include <stdio.h>
#include <stdlib.h>

int main()
{
	int	num, doc_num, what_num, max, point = 0, count = 1;
	int	idx = 0, doc_idx = 0;
	int	*doc;
	
	scanf("%d", &num);
	
	while (idx < num)
	{
		scanf("%d %d", &doc_num, &what_num);
		doc = (int *)malloc(doc_num * sizeof(int));

		doc_idx = 0;
		while (doc_idx < doc_num)
			scanf("%d", &doc[doc_idx++]);

		point = 0;
		count = 1;
		while (1)
		{
			doc_idx = 0;
			max = 0;
			while (doc_idx < doc_num)
			{
				if (max < doc[doc_idx])
					max = doc[doc_idx];
				doc_idx++;
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
		idx++;
	}

	return (0);
}
