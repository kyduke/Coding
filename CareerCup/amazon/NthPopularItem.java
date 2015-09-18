// http://www.careercup.com/question?id=5737921569095680

import java.util.*;

class Item {
	String itemId;
	int quantitySold;
}

public class NthPopularItem {
	public static String find(List<Item> items, int i) {
		List<Item> copy;
		int idx, maxIdx, maxQuantity;
		String result;
		
		result = "";
		
		if (i <= 0 || i > items.size()) return result;
		
		copy = new ArrayList<Item>();
		copy.addAll(items);
		maxIdx = 0;
		while (true) {
			maxQuantity = -1;
			for (idx = 0; idx < copy.size(); idx++) {
				if (copy.get(idx).quantitySold > maxQuantity) {
					maxIdx = idx;
					maxQuantity = copy.get(idx).quantitySold;
				}
			}
			i--;
			if (i == 0) {
				result = copy.get(maxIdx).itemId;
				break;
			}
			copy.remove(copy.get(maxIdx));
		}
		
		return result;
	}
	
	public static Item createItem(String itemId, int quantitySold) {
		Item item = new Item();
		item.itemId = itemId;
		item.quantitySold = quantitySold;
		
		return item;
	}

	public static void main(String[] args) {
		List<Item> items;
		
		items = new ArrayList<Item>();
		items.add(createItem("item1", 3));
		items.add(createItem("item2", 5));
		items.add(createItem("item3", 1));
		items.add(createItem("item4", 2));
		items.add(createItem("item5", 1));
		
		System.out.println(find(items, 2));
		System.out.println(find(items, 3));
	}
}
