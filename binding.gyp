{
	'targets': [{
		'target_name' : 'shell',
		'sources'     : [ 'execsync.cc' ],
    "include_dirs" : [
        "<!(node -e \"require('nan')\")"
    ]
	},],
}
