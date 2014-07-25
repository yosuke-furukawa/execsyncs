var newExecSync = require("child_process").execSync;
if (newExecSync) {
  module.exports = newExecSync;
} else {
  var oldExecSync = require("./execsync");
  module.exports = oldExecSync;
}
