#!/bin/awk -f

BEGIN {
	FS=","
	stats["ALL"] = "ALL"
}

function getStats(column) {
	if ($5 > bestOverall[column]) {
		bestOverallName[column] = $2
		bestOverall[column] = $5
	}

	least = bestOverall[column]
	if ($5 < least) {
		worstOverallName[column] = $2
		least = $5
		worstOverall[column] = least
	}
	
	count[column]++
	sum[column] += $5
	hp[column] += $6
	attack[column] += $7
	defense[column] += $8
	specialAttack[column] += $9
	specialDefense[column] += $10
	speed[column] += $11
}

function displayStats(column) {
	if (column == "ALL") {
		print "Overall most powerful Pokemon: ", bestOverallName[column], " | ", bestOverall[column]
		print "Averages:"
		print "	 HP | ", hp[column] / count[column]
		print "         Attack | ", attack[column] / count[column]
		print "         Defense | ", defense[column] / count[column]
		print "         Special Attack | ", specialAttack[column] / count[column]
		print "         Special Defense | ", specialDefense[column] / count[column]
		print "         Speed | ", speed[column] / count[column]
		print "The ", bestOverallName[column], " is the most powerful ", column, "\n"
		print "Special Statistic:"
		print "		Overall least powerful Pokemon: ", worstOverallName[column], " | ", worstOverall[column]	

	

	}
}

{
	// If number of rows is greater than 1
	if (NR > 1) {
		stats[$3] = $3
		getStats($3)
		getStats($4)
		getStats("ALL")
	}
}


END {
	PROCINFO["sorted_in"] = "@val_str_asc"
	for (column in stats) {
		displayStats(column)
	}
}
