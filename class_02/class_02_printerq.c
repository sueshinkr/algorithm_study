#include <stdio.h>

int main()
{
	int	num, doc_num, what_doc, idx = 0, doc_idx = 0;
	int	*doc;
	
	scanf("%d", &num);
	
	while (idx < num)
	{
		scanf("%d %d", &doc_num, &what_doc);
		doc = (int *)malloc(doc_num * sizeof(int));

		while (doc_idx < doc_num)
			scanf("%d", doc[doc_idx++]);

		

		free(doc);
		idx++;
	}
}
