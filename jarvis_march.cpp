vector<pair<double,double>> jarvis_march(vector<pair<double,double>> points)
{
	vector<pair<double, double>> result;
	pair<double, double> endpoint;
	pair<double, double> pointOnHull = { INFINITY, INFINITY };
	if (points.size() < 3)
		return result;

	int index = 0;
	//find first point (leftmost)
	for (int i = 1; i < points.size(); i++)
	{
		if (points[i].first < pointOnHull.first)
		{
			pointOnHull = points[i];
		}
	}
	
	do
	{
		result.push_back(pointOnHull);
		endpoint = points[0];
		for (int j = 1; j < points.size(); j++)
		{
			if (endpoint == pointOnHull || isLeft(points[j], result[index], endpoint))
				endpoint = points[j];

		}
		index++;
		pointOnHull = endpoint;
	} while (endpoint != result[0]);

	return result;
}

bool isLeft(pair<double, double> s, pair<double, double> r, pair<double, double> end)
{
	pair<double, double> a = { end.first - r.first, end.second - r.second };
	pair<double, double> b = { r.first - s.first, r.second - s.second };
	if (a.first * b.second - a.second * b.first > 0)
		return true;
	return false;
}
