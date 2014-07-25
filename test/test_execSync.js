var assert = require("power-assert");
var execsync = require("..");

describe("execsyncs", function() {
  it('calls ls', function(){
    var result = "" + execsync("ls");
    assert(result.indexOf("execsync.js") > 0);
  });
});
