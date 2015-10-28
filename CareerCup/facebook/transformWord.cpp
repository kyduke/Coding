// http://careercup.com/question?id=5114303424233472

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Word {
	int index;
	int dist;
	int step;
	Word(int i, int d, int s) : index(i), dist(d), step(s) {};
	bool operator<(const Word& a) const {
		return dist > a.dist;
	}
};

string dic[] = {
	"abs", "aby", "ace", "act", "add", "ado", "ads", "aft", "age", "ago", "aid", 
	"ail", "aim", "air", "ait", "ale", "all", "amp", "and", "ant", "any", "ape", 
	"apt", "arc", "are", "ark", "arm", "art", "ash", "ask", "asp", "ass", "ate", 
	"auk", "awe", "awl", "awn", "axe", "azo", "baa", "bad", "bag", "bah", "bam", 
	"ban", "bar", "bat", "bay", "bed", "bee", "beg", "bet", "bey", "bib", "bid", 
	"big", "bin", "bio", "bit", "boa", "bob", "bod", "bog", "boo", "bop", "bot", 
	"bow", "box", "boy", "bra", "bro", "bub", "bud", "bug", "bum", "bun", "bus", 
	"but", "buy", "bye", "cab", "cad", "cam", "can", "cap", "car", "cat", "caw", 
	"cee", "cha", "chi", "cob", "cod", "cog", "con", "coo", "cop", "cot", "cow", 
	"cox", "coy", "cry", "cub", "cud", "cue", "cup", "cur", "cut", "dab", "dad", 
	"dag", "dam", "day", "dee", "den", "dew", "dib", "did", "die", "dig", "dim", 
	"din", "dip", "doe", "dog", "don", "doo", "dop", "dot", "dry", "dub", "dud", 
	"due", "dug", "duh", "dun", "duo", "dux", "dye", "ear", "eat", "ebb", "eel", 
	"egg", "ego", "eke", "elf", "elk", "elm", "emo", "emu", "end", "eon", "era", 
	"erg", "err", "eve", "ewe", "eye", "fab", "fad", "fag", "fan", "far", "far", 
	"fat", "fax", "fay", "fed", "fee", "fen", "few", "fey", "fez", "fib", "fie", 
	"fig", "fin", "fir", "fit", "fix", "fly", "fob", "foe", "fog", "fon", "fop", 
	"for", "fox", "fry", "fun", "fur", "gab", "gag", "gak", "gal", "gap", "gas", 
	"gaw", "gay", "gee", "gel", "gem", "get", "gig", "gil", "gin", "git", "gnu", 
	"gob", "god", "goo", "got", "gum", "gun", "gut", "guy", "gym", "had", "hag", 
	"hal", "ham", "has", "hat", "hay", "hem", "hen", "her", "hew", "hex", "hey", 
	"hid", "him", "hip", "his", "hit", "hoe", "hog", "hop", "hot", "how", "hoy", 
	"hub", "hue", "hug", "hug", "huh", "hum", "hut", "ice", "ick", "icy", "ilk", 
	"ill", "imp", "ink", "inn", "ion", "ire", "irk", "ism", "its", "jab", "jag", 
	"jah", "jak", "jam", "jap", "jar", "jaw", "jay", "jem", "jet", "Jew", "jib", 
	"jig", "job", "joe", "jog", "jon", "jot", "joy", "jug", "jus", "jut", "keg", 
	"key", "kid", "kin", "kit", "koa", "kob", "koi", "lab", "lad", "lag", "lap", 
	"law", "lax", "lay", "lea", "led", "leg", "lei", "let", "lew", "lid", "lie", 
	"lip", "lit", "lob", "log", "loo", "lop", "lot", "low", "lug", "lux", "lye", 
	"mac", "mad", "mag", "man", "map", "mar", "mat", "maw", "max", "may", "men", 
	"met", "mic", "mid", "mit", "mix", "mob", "mod", "mog", "mom", "mon", "moo", 
	"mop", "mow", "mud", "mug", "mum", "nab", "nag", "nap", "nee", "neo", "net", 
	"new", "nib", "nil", "nip", "nit", "nix", "nob", "nod", "nog", "nor", "not", 
	"now", "nub", "nun", "nut", "oaf", "oak", "oar", "oat", "odd", "ode", "off", 
	"oft", "ohm", "oil", "old", "ole", "one", "opt", "orb", "ore", "our", "out", 
	"out", "ova", "owe", "owl", "own", "pac", "pad", "pal", "pan", "pap", "par", 
	"pat", "paw", "pax", "pay", "pea", "pee", "peg", "pen", "pep", "per", "pet", 
	"pew", "pic", "pie", "pig", "pin", "pip", "pit", "pix", "ply", "pod", "pog", 
	"poi", "poo", "pop", "pot", "pow", "pox", "pro", "pry", "pub", "pud", "pug", 
	"pun", "pup", "pus", "put", "pyx", "qat", "qua", "quo", "rad", "rag", "ram", 
	"ran", "rap", "rat", "raw", "ray", "red", "rib", "rid", "rig", "rim", "rip", 
	"rob", "roc", "rod", "roe", "rot", "row", "rub", "rue", "rug", "rum", "run", 
	"rut", "rye", "sac", "sad", "sag", "sap", "sat", "saw", "sax", "say", "sea", 
	"sec", "see", "set", "sew", "sex", "she", "shy", "sic", "sim", "sin", "sip", 
	"sir", "sis", "sit", "six", "ski", "sky", "sly", "sob", "sod", "som", "son", 
	"sop", "sot", "sow", "soy", "spa", "spy", "sty", "sub", "sue", "sum", "sun", 
	"sun", "sup", "tab", "tad", "tag", "tam", "tan", "tap", "tar", "tat", "tax", 
	"tea", "tee", "ten", "the", "tic", "tie", "til", "tin", "tip", "tit", "toe", 
	"toe", "tom", "ton", "too", "top", "tot", "tow", "toy", "try", "tub", "tug", 
	"tui", "tut", "two", "ugh", "uke", "ump", "urn", "use", "van", "vat", "vee", 
	"vet", "vex", "via", "vie", "vig", "vim", "voe", "vow", "wad", "wag", "wan", 
	"war", "was", "wax", "way", "web", "wed", "wee", "wen", "wet", "who", "why", 
	"wig", "win", "wit", "wiz", "woe", "wog", "wok", "won", "woo", "wow", "wry", 
	"wye", "yak", "yam", "yap", "yaw", "yay", "yea", "yen", "yep", "yes", "yet", 
	"yew", "yip", "you", "yow", "yum", "yup", "zag", "zap", "zed", "zee", "zen", 
	"zig", "zip", "zit", "zoa", "zoo"
};
int length = sizeof(dic) / sizeof(dic[0]);

int diffCount(string& a, string& b) {
	int i, cnt;

	cnt = 0;
	for (i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) cnt++;
	}

	return cnt;
}

int transformWord(string source, string target) {
	priority_queue<Word> q;
	vector<int> visit;
	int i;

	visit.assign(length, 0);

	i = 0;
	while (i < length) {
		if (source.compare(dic[i]) == 0) {
			q.push(Word(i, diffCount(source, target), 0));
			visit[i] = 1;
			break;
		}
		i++;
	}

	while (!q.empty() ) {
		Word t = q.top();
		q.pop();

		if (t.dist == 0) return t.step;

		i = 0;
		while (i < length) {
			if (visit[i] == 0 && diffCount(dic[t.index], dic[i]) == 1) {
				q.push(Word(i, diffCount(target, dic[i]), t.step + 1));
				visit[i] = 1;
			}
			i++;
		}
	}
	
	return 0;
}

int main(int argc, char* argv[]) {
	cout << transformWord("cat", "dog") << "\n";
	cout << transformWord("dog", "cat") << "\n";
	cout << transformWord("abs", "zoo") << "\n";
	cout << transformWord("zoo", "abs") << "\n";

	return 0;
}
