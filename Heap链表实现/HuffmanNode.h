#ifndef HUFFMANNODE_H_
#define HUFFMANNODE_H_
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class HuffmanTree;

class HuffmanNode
{
	friend HuffmanTree;
	public:
		HuffmanNode();
		HuffmanNode(const char &str,int &freq);
		HuffmanNode(HuffmanNode &other);
		
		bool operator >(HuffmanNode &other)
		{
			return (freq > other.freq);
		}
		
		bool operator ==(HuffmanNode &other)
		{
			return (freq == other.freq);
		}
		
		bool operator <(HuffmanNode &other)
		{
			return (freq <other.freq);
		}
	private:
		char str;
		int freq;
		
		HuffmanNode *left;
		HuffmanNode *right;
};

HuffmanNode::HuffmanNode()
{
	str = 0;
	freq = 0;
	left = 0;
	right = 0;
}
HuffmanNode::HuffmanNode(const char &s,int &f)
{
	str = s;
	freq = f;
	left = 0;
	right = 0;
}

HuffmanNode::HuffmanNode(HuffmanNode &other)
{
	str = other.str;
	freq = other.freq;
	left = other.left;
	right = other.right;
}
#endif
