#! /usr/bin/perl -w

use strict;

my $num = $ARGV[0];
system("./src/Simple_DataBase < testcases/test$num.txt > testcases/out$num.txt");
my @out = `diff testcases/out$num.txt testcases/expected$num.txt`;
if (scalar(@out) > 0) {
	print "Different results: \n";
	print join("\n", @out);
	print "\n";
}
else {
	print "Results correct.\n";
}
