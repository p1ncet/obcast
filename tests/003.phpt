--TEST--
--SKIPIF--
<?php if(!extension_loaded('obcast')) echo 'skip'; ?>
--FILE--
<?php

class TrueClass implements Boolable {
	public function __toBoolean() {
		return true;
	}
	public function __toString() {
        return 'asdfsdfsdf';
    }
}

$b = new TrueClass();
var_dump((string) $b);
--EXPECT--
string(10) "asdfsdfsdf"