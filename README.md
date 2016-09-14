[![Build Status](https://travis-ci.org/p1ncet/obcast.png)](https://travis-ci.org/p1ncet/obcast)

# obcast
PHP7 only. It allows to cast an object to boolean by implementing new internal interface <i>Boolable</i>

## Example
<pre>
$obj = new class implements Boolable {
		public $container = [];
		public function __toBoolean() {
			return count($this->container) > 0;
		}
};

var_dump((bool) $obj);

$obj->container = [1];
var_dump((bool) $obj);
</pre>
### Output
<pre>
bool(false)
bool(true)
</pre>
