/**
 * Signs an app and copies the result to the specified output directory.
 *
 * @copyright
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 *
 * @license
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

const
	appc = require('node-appc'),
	fs = require('fs'),
	path = require('path'),
	wrench = require('wrench'),
	__ = appc.i18n(__dirname).__;

exports.cliVersion = '>=3.2';

exports.init = function (logger, config, cli) {

	cli.on('build.post.compile', {
		priority: 10000,
		post: function (builder, finished) {
			if (builder.buildOnly || builder.target !== 'dist-phonestore') {
				return finished();
			}

			var wpARMDir = builder.cmakeTargetDir,
				releaseDir = path.join(wpARMDir, 'Release'),
				bundle = path.join(releaseDir, fs.readdirSync(releaseDir).filter(function (f) {
					return f.indexOf('_Bundle') >= 0;
				})[0]),
				appx = path.join(bundle, fs.readdirSync(bundle).filter(function (f) {
					return f.indexOf('.appx') >= 0 && f.indexOf('_scale') === -1;
				})[0]),
				outputDir = builder.outputDir,
				dest = path.join(outputDir, path.basename(appx));

			if (outputDir && outputDir != path.dirname(appx)) {
				fs.existsSync(outputDir) || wrench.mkdirSyncRecursive(outputDir);
				fs.existsSync(dest) && fs.unlinkSync(dest);
				appc.fs.copyFileSync(appx, dest, {logger: logger.debug});
			}

			logger.info(__('Packaging complete'));
			logger.info(__('Package location: %s', dest.cyan));
		}
	});

};
