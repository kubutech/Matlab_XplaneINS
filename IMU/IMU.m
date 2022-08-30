classdef IMU < matlab.System & coder.ExternalDependency
        % IMU- this block sends its inputs to active X-Plane simulation using shared memory. Note: in order for this block to work, special X-Plane plugin needs to be installed
    
        properties(Access = public)
        
        end
            
        properties(DiscreteState)
    
        end
    
        properties(Access = private)
    
        end
    
        methods(Access = protected)
            function setupImpl(obj)
                    coder.cinclude('IMU.h');
                    coder.ceval('setup_IMU');
            end
    
            function [p,q,r,ax,ay,az] = stepImpl(obj)
                p = single(0);
                q = single(0);
                r = single(0);
                ax = single(0);
                ay = single(0);
                az = single(0);
                coder.cinclude('IMU.h');
                coder.ceval('update_IMU');
                p = coder.ceval('get_p');
                q = coder.ceval('get_q');
                r = coder.ceval('get_r');
                ax = coder.ceval('get_ax');
                ay = coder.ceval('get_ay');
                az = coder.ceval('get_az');
            end
    
            function resetImpl(obj)
                
            end
            
            function releaseImpl(obj)
                coder.cinclude('IMU.h');
                coder.ceval('close_IMU');
            end
        end
            
        methods (Static)
            function name = getDescriptiveName()
                name = 'IMU';
            end
            function b = isSupportedContext(context)
                b = context.isCodeGenTarget('rtw');
            end
            function updateBuildInfo(buildInfo, context)
            % Update the build-time buildInfo
                blockRoot = fileparts(mfilename('fullpath'));
                buildInfo.addIncludePaths({blockRoot});
                buildInfo.addIncludeFiles({'IMU.h'});
                buildInfo.addSourcePaths({blockRoot});
                buildInfo.addSourceFiles({'IMU.c'});
            end
        end
    end