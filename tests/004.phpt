--TEST--
--SKIPIF--
<?php if(!extension_loaded('obcast')) echo 'skip'; ?>
--FILE--
<?php

class TrueClass implements Boolable {
	public function __toBoolean() {
		return true;
	}
}

$start_memory = memory_get_usage(true);
var_dump($start_memory);

for ($i = 0; $i < 50000; $i++) {
    $c{$i} = new TrueClass();

    $c{$i}->__toBoolean();
    (bool) $c{$i};
    boolval($c{$i});
    if ($c{$i}) {
    } else {
    }
    $c{$i} ? true : false;
    unset($c{$i});
}
unset($c{$i});

$finish_memory = memory_get_usage(true);
var_dump($finish_memory);
var_dump($finish_memory - $start_memory);

--EXPECT--
int(2097152)
int(2097152)
int(0)