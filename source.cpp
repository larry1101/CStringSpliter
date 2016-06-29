//模拟Excel读csv
//将str以逗号为分割符拆分，返回CStringList；所有单元都返回，包括空的单元；双引号内的无视逗号作为一个整体返回
bool STRAnaylizer(CString str, CStringList* list)
{
	int q1 = str.Find(_T("\""), 0);
	int q2 = str.Find(_T("\""), q1 + 1);

	int com1 = -1;
	int com2 = str.Find(_T(","), com1 + 1);
	while (com2 != -1)
	{
		if (com1 < q1 && com2 > q1)
		{
			CString qcell = str.Mid(q1 + 1, q2 - q1 - 1);
			list->AddTail(qcell);

			com1 = q2 + 1;
			com2 = str.Find(_T(","), q2 + 2);
			q1 = str.Find(_T("\""), q2 + 1);
			q2 = str.Find(_T("\""), q1 + 1);
			continue;
		}
		CString cell = str.Mid(com1 + 1, com2 - com1 - 1);
		list->AddTail(cell);

		com1 = com2;
		com2 = str.Find(_T(","), com2 + 1);
	}

	CString cell = str.Right(str.GetLength() - com1 - 1);

	list->AddTail(cell);

	return true;
}
