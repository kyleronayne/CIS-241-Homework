cpu | sed -nE '/^CPU\(s\):/ p'

echo "======="

echo "Memory:"

echo "=======" 

free -h | sed -n '1,2p' | sed -r 's/Gi/ Gigabytes/g;s/Mi/ Megabytes/g;s/\s\s+/   /g'

echo

echo "Disks:"

echo "======"

df -h | sed -nE '/[0-9]+T/ p'

echo

echo "Date:"

echo "====="

date +"%A, %d %B %Y.%r %Z" | sed -nE 's/AM/a.m./; s/PM/p.m./; s/(EST)/Eastern Standard/p'
