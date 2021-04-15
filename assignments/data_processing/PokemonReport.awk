#! /usr/bin/awk -f 
function getMostPowerful() {
	pokemonTotals = $5
	max = 0
	for (total in pokemonTotals) {
		if (total > max) {
			max = total
		}
		
	}
	print max
}

function main() {
	getMostPowerful()
}

BEGIN {FS=","}
main()
END{}
