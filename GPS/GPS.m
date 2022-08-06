classdef GPS < matlab.System & coder.ExternalDependency
        % GPS- this block sends its inputs to active X-Plane simulation using shared memory. Note: in order for this block to work, special X-Plane plugin needs to be installed
    
        properties(Access = public)
        
        end
            
        properties(DiscreteState)
    
        end
    
        properties(Access = private)
    
        end
    
        methods(Access = protected)
            function setupImpl(obj)
                    coder.cinclude('GPS.h');
                    coder.ceval('setup_GPS');
            end
    
            function [lat,lon,elevation] = stepImpl(obj)
                lat = double(0);
                lon = double(0);
                elevation = double(0);
                coder.cinclude('GPS.h');
                coder.ceval('update_GPS');
                lat = coder.ceval('get_lat');
                lon = coder.ceval('get_lon');
                elevation = coder.ceval('get_elevation');
            end
    
            function resetImpl(obj)
                
            end
            
            function releaseImpl(obj)
                coder.cinclude('GPS.h');
                coder.ceval('close_GPS');
            end
        end
            
        methods (Static)
            function name = getDescriptiveName()
                name = 'GPS';
            end
            function b = isSupportedContext(context)
                b = context.isCodeGenTarget('rtw');
            end
            function updateBuildInfo(buildInfo, context)
            % Update the build-time buildInfo
                blockRoot = fileparts(mfilename('fullpath'));
                buildInfo.addIncludePaths({blockRoot});
                buildInfo.addIncludeFiles({'GPS.h'});
                buildInfo.addSourcePaths({blockRoot});
                buildInfo.addSourceFiles({'GPS.c'});
            end
        end
    end