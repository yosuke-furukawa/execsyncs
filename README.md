execsyncs
===============
[![Build Status](https://travis-ci.org/yosuke-furukawa/execsyncs.svg?branch=master)](https://travis-ci.org/yosuke-furukawa/execsyncs)

execSync for node v0.10 and v0.11.

If your node version is v0.11, execsyncs uses core library (child_process.execSync).
However, if your node version is v0.10, execsyncs uses own native module (execsync.cc).

How to use
================

```shell
$ npm install execsyncs -S
```


```javascript
var execsyncs = require("execsyncs");
var ls = "" + execsyncs("ls");
console.log(ls);
```


LICENSE
===============

MIT

Inspired BY
==============

[https://github.com/hecomi/node-execSync](https://github.com/hecomi/node-execSync)
Thanks, hecomi san.
