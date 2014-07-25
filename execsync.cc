#include <string>
#include <cstdlib>
#include <node.h>
#include <nan.h>

using namespace v8;

NAN_METHOD(execSync) {
  NanScope();

	if (!args[0]->IsString()) {
		NanThrowError("Argument of 'execsync' must be String.");
    NanReturnUndefined();
	}

	const String::Utf8Value utf8_command(args[0]);
	const std::string command = std::string(*utf8_command) + " 2>&1";

	FILE *fp = popen(command.c_str(), "r");
	if (fp == NULL) {
		NanThrowError("'popen' in 'execsync' failed.");
    NanReturnUndefined();
  }

	const int BUF_SIZE = 1024;
	char buf[BUF_SIZE];
	std::string result;
	while ( fgets(buf, BUF_SIZE, fp) != NULL ) {
		result += buf;
	}

	pclose(fp);

  NanReturnValue(NanNew<String>(result.c_str()));
}

void init(Handle<Object> target) {
	target->Set(
		NanNew<String>("execSync"),
		NanNew<FunctionTemplate>(execSync)->GetFunction()
	);
}

NODE_MODULE(shell, init)
