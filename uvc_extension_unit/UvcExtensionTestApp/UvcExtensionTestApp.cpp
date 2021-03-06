// UvcExtensionTestApp.cpp: 定义控制台应用程序的入口点。
//
#include <vidcap.h>
int main()
{
	// pUnkOuter is the unknown associated with the base filter
	hr = pUnkOuter->QueryInterface(__uuidof(IKsTopologyInfo),
		(void **)&pKsTopologyInfo);
	if (!SUCCEEDED(hr))
	{
		printf("Unable to obtain IKsTopologyInfo %x\n", hr);
		goto errExit;
	}

	hr = FindExtensionNode(pKsTopologyInfo,
		GUID_EXTENSION_UNIT_DESCRIPTOR,
		&dwExtensionNode);
	if (FAILED(hr))
	{
		printf("Unable to find extension node : %x\n", hr);
		goto errExit;
	}

	hr = pKsTopologyInfo->CreateNodeInstance(
		dwExtensionNode,
		__uuidof(IExtensionUnit),
		(void **)&pExtensionUnit);
	if (FAILED(hr))
	{
		printf("Unable to create extension node instance : %x\n", hr);
		goto errExit;
	}

	hr = pExtensionUnit->get_PropertySize(1, &ulSize);
	if (FAILED(hr))
	{
		printf("Unable to find property size : %x\n", hr);
		goto errExit;
	}

	pbPropertyValue = new BYTE[ulSize];
	if (!pbPropertyValue)
	{
		printf("Unable to allocate memory for property value\n");
		goto errExit;
	}

	hr = pExtensionUnit->get_Property(1, ulSize, pbPropertyValue);
	if (FAILED(hr))
	{
		printf("Unable to get property value\n");
		goto errExit;
	}

	// assume the property value is an integer
	ASSERT(ulSize == 4);
	printf("The value of property 1 = %d\n", *((int *)
		pbPropertyValue));
    return 0;
}

