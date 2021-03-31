- message.proto

```protobuf
syntax = "proto2";

message Example { 
	required int32 value = 1; 
}
```

- message.pb.c

- message.pb.h

```shell
python D:\important\nanopb-0.4.3-windows-x86\generator\nanopb_generator.py message.proto
```

